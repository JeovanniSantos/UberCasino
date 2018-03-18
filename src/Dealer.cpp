#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_UberCasino.h"

using namespace DDS;
using namespace UberCasino;


int main(int, char**) 
{
  //create new dealer
  
  //start the game
  
  //while game is on publish and subscribe data

  //if game is finsihed ask to start new game or quit

  return 0;
}

/*
function to to act as publisher and writer data passed in as parameter
*/
void Publish()
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
void Subscribe()
{
  DDSEntityManager mgr;
  mgr.createParticipant("Dealer");
  mgr.createSubscriber();
  char topic_name[] = "UberCasinoData";
  mgr.createTopic(topic_name);
  mgr.createWriter();

  /* Remove the DataWriters */
  mgr.deleteWriter();

  /* Remove the Publisher. */
  mgr.deleteSubscriber();

  /* Remove the Topics. */
  mgr.deleteTopic();

  /* Remove Participant. */
  mgr.deleteParticipant();
}

