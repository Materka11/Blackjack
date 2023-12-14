#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>

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
  void getCards(string name);
  void resetHand();
};

#endif