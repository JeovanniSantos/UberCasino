#define DEBUG

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
#include "deck.h"
#include "uuid.h"

using namespace DDS;
using namespace UberCasino;
using namespace std;

class UCDealer{
  
private:
    Dealer d;
    Game g;
    Deck deck;
public:
  UCDealer(){

  }
  
  /*** Function to Setup Deck ***/ //need to update
  void SetDeck(){
    deck.create_test_deck();
    deck.create_eight_deck();
    deck.create_infinite_deck();
  }


  /*** Function to Setup Dealer ***/
  void SetDealer(){
    //needs to set uuid for dealer and game using generator
    const char * DealerUid = uuid_generator();
    const char * GameUid = uuid_generator();
    strcpy(d.uid, DealerUid);
    strcpy(d.name, "Test Dealer");
    strcpy(d.game_uid, GameUid);
  }

  /*** Function to Setup Game Setting ***/
  void SetGame(){
    g.gstate = waiting_to_join;
    strcpy(g.game_uid, d.game_uid);
    strcpy(g.dealer_uid, d.uid);
  }
  
  /*** Function to set the Game State ***/
  void SetGameState(game_state gs){
    g.gstate = gs;
  }
  
  /*** Funtion to add a player to PlayerState ***/
  void AddPlayer(int num, char * uid){
    strcpy(g.p[num].uid, uid);
  }

  /*** Function to send a card to Player ***/
  void SetCard(int player, int count){
    //generate a random card
    card_t c = deck.deal_a_card();
    g.p[player].cards[count] = c;
  }

  /*** Needs to be replaced with toString() Function to retrieve a player's card type ***/
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

  /*** Needs to be replaced with toString() Function to retrieve a player's card suite type ***/
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
    mgr.createParticipant("");

    //Create Type
    GameTypeSupportInterface_var pts = new GameTypeSupport();
    mgr.registerType(pts.in());
    
    //Create Topic
    char topic_name[] = "game";
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
#ifdef DEBUG
      cout << "=== [Dealer] Looking for Players to join :" << endl;
      cout << "    Game ID    : " << GameInstance.game_uid << endl;
      cout << "    Dealer ID  : " << GameInstance.dealer_uid << endl;
#endif
    }
    
    //if game state is playing, the dealer should destribute cards to each player
    else if(GameInstance.gstate == playing){
      // Generate a card for each player
      (*d)->SetCard(0, 0);
      string card = (*d)->GetPlayerCard(0, 0);
      string suite = (*d)->GetPlayerCardSuite(0, 0);

#ifdef DEBUG    
      cout << "=== [Dealer] dealing card to player :" << endl;
      cout << "    Player 0 was dealt a " << card << " of " << suite << endl; 
#endif  
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
    os_time delay_5s = { 5, 0 };

    //Create Participant
    mgr.createParticipant("");

    //Create Type
    PlayerTypeSupportInterface_var pts = new PlayerTypeSupport();
    mgr.registerType(pts.in());

    //Create Topic
    char topic_name[] = "player";
    mgr.createTopic(topic_name);

    //Create Subscriber
    mgr.createSubscriber();

    //Create Reader
    mgr.createReader();

    DataReader_var dr = mgr.getReader();  
    PlayerDataReader_var PlayerReader = PlayerDataReader::_narrow(dr.in());
    checkHandle(PlayerReader.in(), "PlayerDataReader::_narrow");

    Game GameInstance;
    GameInstance = (*d)->GetGame();

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
        if(GameInstance.gstate == waiting_to_join){
          (*d)->AddPlayer(0, ps[i].uid);
          char * uid = ps[i].uid;
#ifdef DEBUG
          cout << "=== [Dealer] adding player to game :" << endl;
          cout << " Player with ID " << uid << " was added to the game." << endl;
#endif
        }
        else if(GameInstance.gstate == playing){
#ifdef DEBUG
          cout << "=== [Dealer] Player has submitted an action :" << endl;
#endif
          //Here Dealer should check for action submitted by Player
          if(player_action_t::hitting == ps[i].A){
            //Send Player a card
            Publish(d);
            os_nanoSleep(delay_5s);
          }
        }
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

  os_time delay_5s = { 5, 0 };

  //Publish the Game so Players can join
  Publish(&d);

  // Find 1-7 players to join the game
  Subscribe(&d);

  //start the game
  d->StartGame();
  Publish(&d);
  os_nanoSleep(delay_5s);
  //send 10 queen of spades to the player
  for(int i = 0; i < 10; i++){
    /*Based on action from Player, Dealer should publish to Player from
      inside subscribe
    */
    Subscribe(&d);
    //Publish(&d);
  }

  //if game is finsihed ask to start new game or quit

  return 0;
}


