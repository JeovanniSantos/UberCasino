#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_dds_dcps.h"
#include "ccpp_UberCasino.h"
#include "vortex_os.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

using namespace DDS;
using namespace UberCasino;
using namespace std;

class UCDealer{
  
private:
    Dealer d;
    Game g;
public:
  UCDealer(){

  }
  
  /*** Function to Setup Dealer ***/
  void SetDealer(){
    strcpy(d.uuid, "1111");
    strcpy(d.name, "Test Dealer");
    strcpy(d.game_uuid, "12345");
  }

  /*** Function to Setup Game Setting ***/
  void SetGame(){
    g.gstate = waiting_to_join;
    strcpy(g.game_uid, d.game_uuid);
    strcpy(g.dealer_uid, d.uuid);
  }
  
  /*** Funtion to add a player to PlayerState ***/
  void AddPlayer(int num, char * uuid){
    strcpy(g.p[num].uuid, uuid);
  }

  /*** Function to send a card to Player ***/
  void SetCard(int player, int count){
    //generate a random card
    card_t c;
    c.card = queen;
    c.suite = spades;
    g.p[player].cards[count] = c;
  }

  /*** Function to retrieve a player's card type ***/
  string GetPlayerCard(int player, int count){
    card_t c = g.p[player].cards[count];
    char r[10];
    switch( c.card )
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
  string GetPlayerCardSuite(int player, int count){
    card_t c = g.p[player].cards[count];
    char r[10];

    switch( c.suite )
    {
      case suite_t::hearts: strcpy(r, "hearts"); break;
      case suite_t::diamonds: strcpy(r, "diamonds"); break;
      case suite_t::clubs: strcpy(r, "clubs"); break;
      case suite_t::spades: strcpy(r, "spades"); break;
    }
    return string(r);
  } 

  /*** Function to Start the game ***/
  void StartGame(){
    g.gstate = playing;
  }

  /*** Function to get the Dealer struct ***/
  Dealer GetDealer(){
    return d;
  }

  /*** Function to get the Game Struct ***/
  Game GetGame(){
    return g;
  }

};//end of class declaration

/*
  function to to act as publisher and write data passed in as parameter
  */
  void Publish(UCDealer **d)
  {
    DDSEntityManager mgr;

    os_time delay_1s = { 1, 0 };
    
    //Create Participant
    mgr.createParticipant("UberCasino");

    //Create Type
    GameTypeSupportInterface_var pts = new GameTypeSupport();
    mgr.registerType(pts.in());
    
    //Create Topic
    char topic_name[] = "Game";
    mgr.createTopic(topic_name);

    //Create Publisher
    mgr.createPublisher();

    // create DataWriter :
    // If autodispose_unregistered_instances is set to true (default value),
    // you will have to start the subscriber before the publisher
    bool autodispose_unregistered_instances = false;
    mgr.createWriter(autodispose_unregistered_instances);
    
    //Publish Events based on action 
    DataWriter_var dw = mgr.getWriter(); 
    GameDataWriter_var GameWriter;
    Game GameInstance;
    Game newGame;

    GameWriter = GameDataWriter::_narrow(dw.in());
    checkHandle(GameWriter.in(), "GameDataWriter::_narrow");
    GameInstance = (*d)->GetGame();
    
    if(GameInstance.gstate == waiting_to_join){
      cout << "=== [Dealer Publisher] writing a message containing :" << endl;
      cout << "    Game State : " << GameInstance.gstate << endl;
      cout << "    Game ID    : " << GameInstance.game_uid << endl;
      cout << "    Dealer ID  : " << GameInstance.dealer_uid << endl;
    }
    
    //if game state is playing, the dealer should destribute cards to each player
    else if(GameInstance.gstate == playing){
      // Generate a card for each player
      (*d)->SetCard(0, 0);
      string card = (*d)->GetPlayerCard(0, 0);
      string suite = (*d)->GetPlayerCardSuite(0, 0);
      cout << "=== [Dealer Publisher] writing a message containing :" << endl;
      cout << "    Game State : " << GameInstance.gstate << endl;
      cout << "    Game ID    : " << GameInstance.game_uid << endl;
      cout << "    Dealer ID  : " << GameInstance.dealer_uid << endl;
      cout << "    Player 0 was dealt a " << card << " of " << suite << endl;      
    }
    //cards were were distributed and game was changed
    newGame = (*d)->GetGame();
    ReturnCode_t status = GameWriter->write(newGame,          DDS::HANDLE_NIL);
    checkStatus(status, "GameDataWriter::write");

    os_nanoSleep(delay_1s);

    /* Remove the DataWriters */
    mgr.deleteWriter();

    /* Remove the Publisher. */
    mgr.deletePublisher();

    /* Remove the Topics. */
    mgr.deleteTopic();

    /* Remove Participant. */
    mgr.deleteParticipant();
    
    cout << "=== [Dealer Publisher] exiting..." << endl;
  }

  /*
  function to to act as subscriber and read data passed in as parameter
  */
  static void Subscribe(UCDealer **d)
  {
    DDSEntityManager mgr;
    PlayerSeq ps;
    SampleInfoSeq infoSeq;

    os_time delay_2ms = { 0, 2000000 };
    os_time delay_200ms = { 0, 200000000 };

    //Create Participant
    mgr.createParticipant("UberCasino");

    //Create Type
    PlayerTypeSupportInterface_var pts = new PlayerTypeSupport();
    mgr.registerType(pts.in());

    //Create Topic
    char topic_name[] = "Player";
    mgr.createTopic(topic_name);

    //Create Subscriber
    mgr.createSubscriber();

    //Create Reader
    mgr.createReader();

    DataReader_var dr = mgr.getReader();  
    PlayerDataReader_var PlayerReader = PlayerDataReader::_narrow(dr.in());
    checkHandle(PlayerReader.in(), "PlayerDataReader::_narrow");

    cout << "=== [Dealer Subscriber] Ready ..." << endl;
    bool found = false;
    ReturnCode_t status = -1;

     //We don't want to read indefinitly so we will search until something is found
    while(!found)
    {
      status = PlayerReader->take(ps, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
      
      checkStatus(status, "PlayerDataReader::take");
      DDS::ULong i;
      for(i = 0; i < ps.length(); i++)
      {
	cout << "=== [Dealer Subscriber] message received :" << endl;
        cout << "    Player ID  : " << ps[i].uuid << endl;
        cout << "    Game ID : " << ps[i].game_uid << endl;
        cout << "    Dealer ID : " << ps[i].dealer_uid << endl;
        (*d)->AddPlayer(0, ps[i].uuid);
        Game GameInstance = (*d)->GetGame();
        cout << " Player with ID " << GameInstance.p[0].uuid << " was added to the game." << endl;
	found = true;
      }

      status = PlayerReader->return_loan(ps, infoSeq);
      checkStatus(status, "PlayerDataReader::return_loan");
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

    cout << "=== [Dealer Subscriber] Closing ..." << endl;
  }


/** MAIN FUNCTION **/
int main(int argc, char **argv) 
{
  /*Open a new Window to start Game for Dealer 
    Window will ask dealer for input 
    a button will determine if Dealer progresses to a new game
  */
  //bool startGame = false;

  //create new dealer with input information
  UCDealer *d = new UCDealer();
  d->SetDealer();
  d->SetGame();

  //Publish Game to Players
  os_time delay_5s = { 5, 0 };

  //Publish the Game so Players can join
  Publish(&d);

  // Find 1-7 players to join the game
  Subscribe(&d);

  //start the game
  d->StartGame();
  
  //send 10 queen of spades to the player
  for(int i = 0; i < 10; i++){
    Publish(&d);
    os_nanoSleep(delay_5s);
  }

  //if game is finsihed ask to start new game or quit

  return 0;
}


