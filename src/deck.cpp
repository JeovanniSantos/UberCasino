#include "deck.h"
#include <time.h>

using namespace DDS;
using namespace UberCasino;
using namespace std;

//Function to create the deck. This is separate from the constructor
//as the deck will need to be recreated if it gets low on cards
void Deck::create_test_deck(){
	for(unsigned int i = 1, j = 0; i < 14 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)1;
		new_card.suite=(suite_t)1;
		deck.push_back(new_card);
		if(i == 13){
			j++;
			i = 0;
		}
	}
}

void Deck::create_eight_deck(){
	int count_deck=0;
	while(count_deck<8){
	for(unsigned int i = 1, j = 0; i < 14 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)1;
		new_card.suite=(suite_t)1;
		deck.push_back(new_card);
		if(i == 13){
			j++;
			i = 0;
		}
	}
	count_deck++;
	}
}

void Deck::create_infinite_deck(){
	int count_deck=0;
	while(count_deck<16){
	for(unsigned int i = 1, j = 0; i < 14 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)1;
		new_card.suite=(suite_t)1;
		deck.push_back(new_card);
		if(i == 13){
			j++;
			i = 0;
		}
	}
	count_deck++;
	}
}


//Function selects a random card from the deck and returns it to the caller
UberCasino::card_t Deck::deal_a_card(){
	card_t new_card;
	srand( time(NULL) );
	int r = rand() % (deck.size());
	new_card = deck.at(r);
	deck.erase(deck.begin() + r);

	return new_card;
}

int Deck::num_cards(){
	return deck.size();
}

//Destructor - destroys cards when deck is destroyed (Allegro Bitmap issue)
Deck::~Deck(){
	deck.clear();
}
