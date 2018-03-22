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
  
public:
  UCDealer();
  Dealer d;
  
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
    
    //Publish Events
    DataWriter_var dw = mgr.getWriter();  
    GameDataWriter_var GameWriter = GameDataWriter::_narrow(dw.in());

    checkHandle(GameWriter.in(), "GameDataWriter::_narrow");

    Game GameInstance;
    strcpy(GameInstance.game_uid, "1" );
    strcpy(GameInstance.dealer_uid, "2" );
    //GameWriter->register_instance(GameInstance);
 
    cout << "=== [Dealer Publisher] writing a message containing :" << endl;
    cout << "    Game ID   : " << GameInstance.game_uid << endl;
    cout << "    Dealer ID : " << GameInstance.dealer_uid << endl;

    ReturnCode_t status = GameWriter->write(GameInstance,          DDS::HANDLE_NIL);
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

};//end of class declaration

UCDealer::UCDealer()
{

}

/** MAIN FUNCTION **/
int main(int argc, char **argv) 
{
  //create new dealer
  UCDealer *d = new UCDealer();

  //Open a new Window to start Game
  //d->Publish();
  d->Subscribe();

  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit

  return 0;
}


