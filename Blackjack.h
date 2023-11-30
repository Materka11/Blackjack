#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Hand.h"

class Blackjack
{
private:
  Deck deck;
  Hand playerHand;
  Hand dealerHand;

public:
  Blackjack();
  void startGame();
  void endGame();
};

#endif