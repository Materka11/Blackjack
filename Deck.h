#ifndef DECK_H
#define DECK_H

#include "Card.h"

using namespace std;

class Deck
{
private:
  char cardsRank[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
  string cardsSuit[4] = { "Kier", "Karo", "Trefl", "Pik" };
  int CARDS_RANK_LENGHT;
  int CARDS_SUIT_LENGHT;
  Card deck[52];

public:
  Deck();
  void shuffle();
  Card getRandomCard() const;
};

#endif