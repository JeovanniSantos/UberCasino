#ifndef DECK_H
#define DECK_H

#include "UberCasino.h"
#include <vector>

//This is the class for the deck of cards. It a vector of cards

enum deck_type {test,eight_deck,infinite};

class Deck
{
	public:
		//Constructor and destructor
		Deck(){

                }
		~Deck();
		void create_test_deck();
		void create_eight_deck();
		void create_infinite_deck();


		//Function that removes a card from the vector and returns
		//it to the caller
		UberCasino::card_t deal_a_card();

		//Getter retuns number of cards in the deck
		int num_cards();

	private:
		std::vector<UberCasino::card_t> deck;
		
};

#endif
