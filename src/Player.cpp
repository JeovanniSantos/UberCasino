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

  /*
  function to to act as publisher and write data passed in as parameter
  */
  static void Publish()
  {
    DDSEntityManager mgr;
    mgr.createParticipant("UberCasino");
    mgr.createPublisher();
    char topic_name[] = "Dealer";
    mgr.createTopic(topic_name);
    mgr.createWriter();

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

    cout << "=== [Subscriber] Ready ..." << endl;
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
	cout << "=== [Subscriber] message received :" << endl;
        //cout << "    DealerID  : " << ps[i].dealer_uid << endl;
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
    cout << "=== [Subscriber] Closing ..." << endl;
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
  p->Subscribe();
  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit
  /*
  Fl_Window *window = new Fl_Window(340,180);
  Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
*/
  return 0;
}


