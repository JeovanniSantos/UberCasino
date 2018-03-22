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

class UCDealer{
  
public:
  UCDealer();

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
 
    cout << "=== [Publisher] writing a message containing :" << endl;
    cout << "    game ID  : " << GameInstance.game_uid << endl;
    cout << "    dealer ID : " << GameInstance.dealer_uid << endl;

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
  }

  /*
  function to to act as subscriber and read data passed in as parameter
  */
  static void Subscribe()
  {
    DDSEntityManager mgr;
    mgr.createParticipant("Dealer");
    mgr.createSubscriber();
    char topic_name[] = "UberCasinoData";
    mgr.createTopic(topic_name);
    mgr.createReader();

    /* Remove the DataReaders */
    mgr.deleteReader();

    /* Remove the Subscriber. */
    mgr.deleteSubscriber();

    /* Remove the Topics. */
    mgr.deleteTopic();

    /* Remove Participant. */
    mgr.deleteParticipant();
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
  d->Publish();
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


