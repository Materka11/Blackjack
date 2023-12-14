#include "Hand.h"
#include <iostream>

using namespace std;


Hand::Hand(Deck deck, bool isDealer) {
	this->deck = deck;
	if (isDealer) {
		addCard();
	}
	else {
		addCard();
		addCard();
	}
}

void Hand::addCard() {
	const Card card = deck.getRandomCard();
	cards.push_back(card); 
}

int Hand::getPoints() {
	int totalPoints = 0;

	for (const auto& card : cards) {
		totalPoints += card.getValue(totalPoints);
	}
	return totalPoints;
	
}

void Hand::getCards(string name) {
	cout << "Karty w rece: " + name << endl << endl;
	for (const auto& card : cards) {
		cout << "Karta: " << card.getRank() << " " << card.getSuit() << endl;
	}
	cout << endl;
}

void Hand::resetHand() {
	cards.clear();
}