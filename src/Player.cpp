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

};//end of class declaration

/*
  function to to act as publisher and write data passed in as parameter
  */
  static void Publish()
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
    PlayerDataWriter_var PlayerWriter = PlayerDataWriter::_narrow(dw.in());

    checkHandle(PlayerWriter.in(), "PlayerDataWriter::_narrow");

    Player PlayerInstance;
    strcpy(PlayerInstance.uuid, "1" );
    strcpy(PlayerInstance.name, "Player" );

    cout << "=== [Player Publisher] writing a message containing :" << endl;
    cout << "    Player ID   : " << PlayerInstance.uuid << endl;
    cout << "    Player name : " << PlayerInstance.name << endl;

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
  static void Subscribe(char* action, PlayerUC p)
  {
    DDSEntityManager mgr;
    GameSeq gs;
    PlayerSeq ps;
    SampleInfoSeq infoSeq;

    os_time delay_2ms = { 0, 2000000 };
    os_time delay_200ms = { 0, 200000000 };
    
    //Create Participant
    mgr.createParticipant("UberCasino");

    //Create Type based on action 
    if(strcmp("Game", action) == 0){
      GameTypeSupportInterface_var pts = new GameTypeSupport();
      mgr.registerType(pts.in());
    }
    else if(strcmp("Player", action) == 0){
      PlayerTypeSupportInterface_var pts = new PlayerTypeSupport();
      mgr.registerType(pts.in());
    }

    //Create Topic
    char *topic_name = action;
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

    if(strcmp("Game", action) == 0){
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
	  cout << "=== [Player Subscriber] message received :" << endl;
          cout << "    Game ID   : " << gs[i].game_uid << endl;
          cout << "    Dealer ID : " << gs[i].dealer_uid << endl;
	  found = true;
        }

        status = GameReader->return_loan(gs, infoSeq);
        checkStatus(status, "GameDataReader::return_loan");
        os_nanoSleep(delay_200ms);
      }
    } 
    else if(strcmp("Player", action) == 0){
      PlayerReader = PlayerDataReader::_narrow(dr.in());
      checkHandle(PlayerReader.in(), "PlaerDataReader::_narrow");

      //We don't want to read indefinitly so we will search until something is found
      while(!found)
      {
        status = PlayerReader->take(ps, infoSeq, LENGTH_UNLIMITED,
        ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
      
        checkStatus(status, "PlayerDataReader::take");
        DDS::ULong i;
        for(i = 0; i < ps.length(); i++)
        {
	  cout << "=== [Player Subscriber] message received :" << endl;
          cout << "    Player ID   : " << ps[i].uuid << endl;
          cout << "    Player name : " << ps[i].name << endl;
	  found = true;
        }

        status = PlayerReader->return_loan(ps, infoSeq);
        checkStatus(status, "PlayerDataReader::return_loan");
        os_nanoSleep(delay_200ms);
      }
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
  
  char game[] = "Game";
  char player[] = "Player";
  os_time delay_5s = { 5, 0 };
  while(1){
    Subscribe(game, *p);
    //wait 5 secs
    os_nanoSleep(delay_5s);
    Publish();
  }
  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit
 
  return 0;
}


