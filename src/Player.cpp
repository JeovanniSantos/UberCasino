#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_dds_dcps.h"
#include "ccpp_UberCasino.h"
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
    mgr.createParticipant("Player");
    mgr.createPublisher();
    char topic_name[] = "UberCasinoData";
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
    PlayerSeq ps;
    SampleInfoSeq infoSeq;
    //Create Participant
    mgr.createParticipant("UberCasino");

    //Create Subscriber
    mgr.createSubscriber();
    PlayerTypeSupportInterface_var pts = new PlayerTypeSupport();
    mgr.registerType(pts.in());
    
    //Create Topic
    char topic_name[] = "Dealer";
    mgr.createTopic(topic_name);

    //Create Reader
    mgr.createReader();

    DataReader_var dr = mgr.getReader();  
    PlayerDataReader_var PlayerReader = PlayerDataReader::_narrow(dr.in());
    checkHandle(PlayerReader.in(), "PlayerDataReader::_narrow");

    cout << "=== [Subscriber] Ready ..." << endl;
    bool found = false;
    
    //We don't want to read indefinitly so we will search until something is found
    while(!found)
    {
      PlayerReader->take(ps, infoSeq, LENGTH_UNLIMITED,
      ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
      
      DDS::ULong i;
      for(i = 0; i < ps.length(); i++)
      {
	cout << "=== [Subscriber] message received :" << endl;
	found = true;
      }
    }
    PlayerReader->return_loan(ps, infoSeq);

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
int main(int argc, char **argv) 
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

