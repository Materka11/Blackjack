#include "Card.h"

using namespace std;

Card::Card() : cardRank(' '), cardSuit("") {}

Card::Card(char rank, string suit) : cardRank(rank), cardSuit(suit) {}

int Card::getValue(int points) const
{
  if (cardRank >= '2' && cardRank <= '9')
  {
    return cardRank - '0';
  }
  if (cardRank == 'T' || cardRank == 'J' || cardRank == 'Q' || cardRank == 'K')
  {
    return 10;
  }
  if (cardRank == 'A')
  {
    if (points + 11 <= 21)
    {
      return 11;
    }
    else
    {
      return 1;
    }
  }
}