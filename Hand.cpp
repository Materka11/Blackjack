#include "Hand.h"
#include <iostream>
#include <utility>

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

pair<char, string> Hand::getCards() {
	for (const auto& card : cards) {
		return make_pair(card.getRank(), card.getSuit());
	}
}

void Hand::resetHand() {
	cards.clear();
}