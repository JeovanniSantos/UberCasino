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
    strcpy(d.uuid, "1");
    strcpy(d.name, "Test Dealer");
    strcpy(d.game_uuid, "12345");
  }

  /*** Function to Setup Game Setting ***/
  void SetGame(){
    g.gstate = waiting_to_join;
    strcpy(g.game_uid, d.game_uuid);
    strcpy(g.dealer_uid, d.uuid);
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
  void Publish(char* action, UCDealer d)
  {
    DDSEntityManager mgr;

    os_time delay_1s = { 1, 0 };
    
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
    Player PlayerInstance;
    PlayerDataWriter_var PlayerWriter;

    if(strcmp("Game", action) == 0){
      GameWriter = GameDataWriter::_narrow(dw.in());
      checkHandle(GameWriter.in(), "GameDataWriter::_narrow");
      GameInstance = d.GetGame();
      
      cout << "=== [Dealer Publisher] writing a message containing :" << endl;
      cout << "    Game ID   : " << GameInstance.game_uid << endl;
      cout << "    Dealer ID : " << GameInstance.dealer_uid << endl;

      ReturnCode_t status = GameWriter->write(GameInstance,          DDS::HANDLE_NIL);
      checkStatus(status, "GameDataWriter::write");
    }
    else if(strcmp("player", action) == 0){
      PlayerWriter = PlayerDataWriter::_narrow(dw.in());
      checkHandle(PlayerWriter.in(), "PlayerDataWriter::_narrow");
      
      ReturnCode_t status = PlayerWriter->write(PlayerInstance,          DDS::HANDLE_NIL);
      checkStatus(status, "PlayerDataWriter::write");
    }

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
  static void Subscribe()
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
        cout << "    Player name : \"" << ps[i].name << "\"" << endl;
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

  char game[] = "Game";
  char player[] = "Player";
  os_time delay_5s = { 5, 0 };
  while(1){
    Publish(game, *d);
    Subscribe();
    os_nanoSleep(delay_5s);
  }
  
  

  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit

  return 0;
}


