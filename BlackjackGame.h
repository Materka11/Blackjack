#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Hand.h"

class BlackjackGame
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
  BlackjackGame();
  void startGame();
  void playAgain();
  std::vector<std::pair<char, std::string>> getCardsPlayer();
  std::vector<std::pair<char, std::string>> getCardsDealer();
};

#endif