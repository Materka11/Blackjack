#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Hand
{
private:
  vector<Card> cards;
  Deck deck;

public:
  Hand(Deck deck, bool isDealer);
  void addCard();
  int getPoints();
  pair<char, string> getCards();
  void resetHand();
};

#endif