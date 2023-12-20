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
  void hit();
  void stand();
  void surrender();
  void getChoice();
  void resetGame();

public:
  Blackjack();
  void startGame();
  void playAgain();
};

#endif