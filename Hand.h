#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>
#include <utility>


class Hand
{
private:
  std::vector<Card> cards;
  Deck deck;

public:
  Hand(Deck deck, bool isDealer);
  void addCard();
  int getPoints();
  std::vector<std::pair<char, std::string>> getCards();
  void resetHand();
};

#endif