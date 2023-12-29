#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Hand.h"

enum GameResult {
    PLAYER,
    DEALER,
    DRAW
};

class BlackjackGame
{
private:
  Deck deck;
  Hand playerHand;
  Hand dealerHand; 

public:
  void hit();
  GameResult stand();
  BlackjackGame();
  void startGame();
  void resetGame();
  std::vector<std::pair<char, std::string>> getCards(bool isPlayer);
  int getPoints(bool isPlayer);
};

#endif