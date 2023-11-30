#include "Deck.h"

Deck::Deck()
{
  int l = 0;
  for (int i = 0; i < CARDS_SUIT_LENGHT; i++)
  {
    for (int j = 0; j < CARDS_RANK_LENGHT; j++)
    {
      deck[l] = Card(cardsRank[j], cardsSuit[i]);
      l++;
    }
  }
}

void Deck::shuffle() {}