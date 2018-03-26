#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_dds_dcps.h"
#include "ccpp_UberCasino.h"
#include "vortex_os.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

using namespace DDS;
using namespace UberCasino;
using namespace std;

class PlayerUC{
  
private:
  Player p;

public:
  PlayerUC(){

  }

  /*** Function to Setup Player ***/
  void SetPlayer(){
    strcpy(p.uuid, "123");
    strcpy(p.name, "TestPlayer");
    p.balance = 500;
    p.A = idle;
  }

  /*** Function to get the Player Struct ***/
  Player GetPlayer(){
    return p;
  }
  
  /*** Function to Set The player's Game ID ***/
  void SetPlayerGame(char * game, char * dealer){
    strcpy(p.game_uid, game);
    strcpy(p.dealer_uid, dealer);
  }

  /*** Function to retrieve a player's card type ***/
  string GetPlayerCard(card_kind c){
    char r[10];
    switch( c )
    {
      case card_kind::ace: strcpy(r, "ace"); break;
      case card_kind::two: strcpy(r, "two"); break;
      case card_kind::three: strcpy(r, "three"); break;
      case card_kind::four: strcpy(r, "four"); break;
      case card_kind::five: strcpy(r, "five"); break;
      case card_kind::six: strcpy(r, "six"); break;
      case card_kind::seven: strcpy(r, "seven"); break;
      case card_kind::eight: strcpy(r, "eight"); break;
      case card_kind::nine: strcpy(r, "nine"); break;
      case card_kind::ten: strcpy(r, "ten"); break;
      case card_kind::jack: strcpy(r, "jack"); break;
      case card_kind::queen: strcpy(r, "queen"); break;
      case card_kind::king: strcpy(r, "king"); break;
    }
    return string(r);
  }  

  /*** Function to retrieve a player's card suite type ***/
  string GetPlayerCardSuite(suite_t t){
    char r[10];

    switch( t )
    {
      case suite_t::hearts: strcpy(r, "hearts"); break;
      case suite_t::diamonds: strcpy(r, "diamonds"); break;
      case suite_t::clubs: strcpy(r, "clubs"); break;
      case suite_t::spades: strcpy(r, "spades"); break;
    }
    return string(r);
  } 

};//end of class declaration

/*
  function to to act as publisher and write data passed in as parameter
  */
  static void Publish(PlayerUC **p)
  {
    DDSEntityManager mgr;

    os_time delay_1s = { 1, 0 };

    //Create Participant
    mgr.createParticipant("UberCasino");
 
    //Create Type
    PlayerTypeSupportInterface_var pts = new PlayerTypeSupport();
    mgr.registerType(pts.in());

    //Create Topic
    char topic_name[] = "Player";
    mgr.createTopic(topic_name);

    //Create Publisher
    mgr.createPublisher();

    // create DataWriter :
    // If autodispose_unregistered_instances is set to true (default value),
    // you will have to start the subscriber before the publisher
    bool autodispose_unregistered_instances = false;
    mgr.createWriter(autodispose_unregistered_instances);

    //Publish Events
    DataWriter_var dw = mgr.getWriter();  
    PlayerDataWriter_var PlayerWriter =     PlayerDataWriter::_narrow(dw.in());
    Player PlayerInstance;
    checkHandle(PlayerWriter.in(), "PlayerDataWriter::_narrow");
    
    PlayerInstance = (*p)->GetPlayer();
    cout << "=== [Player Publisher] writing a message containing :" << endl;
    cout << "    Player ID   : " << PlayerInstance.uuid << endl;
    cout << "    Game ID : " << PlayerInstance.game_uid << endl;
    cout << "    Dealer ID : " << PlayerInstance.dealer_uid << endl;
   
    ReturnCode_t status = PlayerWriter->write(PlayerInstance,          DDS::HANDLE_NIL);
  checkStatus(status, "PlayerDataWriter::write");
  os_nanoSleep(delay_1s);

    /* Remove the DataWriters */
    mgr.deleteWriter();

    /* Remove the Publisher. */
    mgr.deletePublisher();

    /* Remove the Topics. */
    mgr.deleteTopic();

    /* Remove Participant. */
    mgr.deleteParticipant();

    cout << "=== [Player Publisher] exiting..." << endl;
  }

  /*
  function to to act as subscriber and read data passed in as parameter
  */
  static void Subscribe(PlayerUC **p)
  {
    DDSEntityManager mgr;
    GameSeq gs;
    PlayerSeq ps;
    SampleInfoSeq infoSeq;

    os_time delay_2ms = { 0, 2000000 };
    os_time delay_200ms = { 0, 200000000 };
    
    //Create Participant
    mgr.createParticipant("UberCasino");

    //Create Type
    GameTypeSupportInterface_var pts = new GameTypeSupport();
    mgr.registerType(pts.in());

    //Create Topic
    char topic_name[] = "Game";
    mgr.createTopic(topic_name);

    //Create Subscriber
    mgr.createSubscriber();

    //Create Reader
    mgr.createReader();

    DataReader_var dr = mgr.getReader();  
    GameDataReader_var GameReader;
    PlayerDataReader_var PlayerReader;

    cout << "=== [Player Subscriber] Ready ..." << endl;
    bool found = false;
    ReturnCode_t status = -1;

    GameReader = GameDataReader::_narrow(dr.in());
    checkHandle(GameReader.in(), "GameDataReader::_narrow");

    //We don't want to read indefinitly so we will search until something is found
    while(!found)
    {
      status = GameReader->take(gs, infoSeq, LENGTH_UNLIMITED,
        ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
      
      checkStatus(status, "GameDataReader::take");
      DDS::ULong i;
      for(i = 0; i < gs.length(); i++)
      {
	if(gs[i].gstate == waiting_to_join){
          cout << "=== [Player Subscriber] message received :" << endl;
          cout << "    Game ID   : " << gs[i].game_uid << endl;
          cout << "    Dealer ID : " << gs[i].dealer_uid << endl;
          (*p)->SetPlayerGame(gs[i].game_uid, gs[i].dealer_uid);
        }
        else if(gs[i].gstate == playing){
          string card = (*p)->GetPlayerCard(gs[i].p[0].cards[0].card);
          string suite = (*p)->GetPlayerCardSuite(gs[i].p[0].cards[0].suite);
          cout << "=== [Player Subscriber] message received :" << endl;
          cout << "    Game ID   : " << gs[i].game_uid << endl;
          cout << "    Dealer ID : " << gs[i].dealer_uid << endl;
          cout << "    Dealer dealt a " << card << " of " << suite << endl;  
        }
	found = true;
      }

      status = GameReader->return_loan(gs, infoSeq);
      checkStatus(status, "GameDataReader::return_loan");
      os_nanoSleep(delay_200ms);
    }

    os_nanoSleep(delay_2ms);

    /* Remove the DataReaders */
    mgr.deleteReader();

    /* Remove the Subscriber. */
    mgr.deleteSubscriber();

    /* Remove the Topics. */
    mgr.deleteTopic();

    /* Remove Participant. */
    mgr.deleteParticipant();

    cout << "=== [Player Subscriber] Closing ..." << endl;
  }

/** MAIN FUNCTION **/
int main (int argc, char **argv) 
{
  /*Open a new Window to start Game for Player 
    Window will ask Player for input 
    a button will determine if Dealer progresses to a new game
  */
  //bool startGame = false;
  //bool active = false;

  //create new player with input information
  PlayerUC *p = new PlayerUC();
  p->SetPlayer();
  
  os_time delay_5s = { 5, 0 };

  //Search for game
  Subscribe(&p);
  //wait 5 secs
  os_nanoSleep(delay_5s);

  //Send information to the Dealer hosting the Game
  Publish(&p);
  os_nanoSleep(delay_5s);
  
  //start the game && search for cards dealt by dealer
  
  for(int i = 0; i < 10; i++){
    Subscribe(&p);
    os_nanoSleep(delay_5s);
  }

  //if game is finsihed ask to start new game or quit
 
  return 0;
}


