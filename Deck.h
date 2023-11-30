#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
  char cardsRank[13];
  std::string cardsSuit[4];
  int CARDS_RANK_LENGHT;
  int CARDS_SUIT_LENGHT;
  Card deck[52];

public:
  Deck();
  void shuffle();
};

#endif