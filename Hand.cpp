#include "Hand.h"
#include <iostream>
#include <utility>


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

std::vector<std::pair<char, std::string>> Hand::getCards() {
	std::vector<std::pair<char, std::string>> allCards;
	for (const auto& card : cards) {
		allCards.push_back(std::make_pair(card.getRank(), card.getSuit()));
	}
	return allCards;
}

void Hand::resetHand() {
	cards.clear();
}