#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_UberCasino.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

using namespace DDS;
using namespace UberCasino;
using namespace std;

class Dealer{

  Dealer(){
  }
  
public:
  /*
  function to to act as publisher and write data passed in as parameter
  */
  static void Publish()
  {
    DDSEntityManager mgr;
    mgr.createParticipant("Dealer");
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

/** MAIN FUNCTION **/
int main(int argc, char **argv) 
{
  
  //create new dealer
  
  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit
  
  Fl_Window *window = new Fl_Window(340,180);
  Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
  //return 0;
}

