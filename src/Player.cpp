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
  
public:
  PlayerUC();
  Player p;

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
  static void Subscribe()
  {
    DDSEntityManager mgr;
    GameSeq ps;
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
    GameDataReader_var GameReader = GameDataReader::_narrow(dr.in());
    checkHandle(GameReader.in(), "GameDataReader::_narrow");

    cout << "=== [Player Subscriber] Ready ..." << endl;
    bool found = false;
    ReturnCode_t status = -1;
    
    //We don't want to read indefinitly so we will search until something is found
    while(!found)
    {
      status = GameReader->take(ps, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
      
      checkStatus(status, "GameDataReader::take");
      DDS::ULong i;
      for(i = 0; i < ps.length(); i++)
      {
	cout << "=== [Player Subscriber] message received :" << endl;
        cout << "    Game ID   : " << ps[i].game_uid << endl;
        cout << "    Dealer ID : " << ps[i].dealer_uid << endl;
	found = true;
      }

      status = GameReader->return_loan(ps, infoSeq);
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

};//end of class declaration

PlayerUC::PlayerUC()
{

}

/** MAIN FUNCTION **/
int main (int argc, char **argv) 
{
  // dummy test to recieve data from Dealer  

  // run indefinitely

  //create new player
  PlayerUC *p = new PlayerUC();
  //p->Subscribe();
  p->Publish();
  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit
 
  return 0;
}


