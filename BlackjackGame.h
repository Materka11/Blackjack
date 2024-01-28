#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Hand.h"

enum GameResult {
    PLAYER,
    DEALER,
    DRAW,
    NOBODY
};

class BlackjackGame
{
private:
  Deck deck;
  Hand playerHand;
  Hand dealerHand;
  std::string playerName;
  int bet;

public:
  void hit();
  GameResult stand();
  BlackjackGame();
  void startGame();
  void resetGame();
  std::vector<std::pair<char, std::string>> getCards(bool isPlayer);
  int getPoints(bool isPlayer);
  GameResult giveResultHit();
  void setPlayerName(std::string playerName);
  std::string getPlayerName();
  void setBet(int currentBet);
  int getBet();
};

#endif