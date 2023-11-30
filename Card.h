#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
private:
  char cardRank;
  string cardSuit;

public:
  Card();
  Card(char rank, string suit);
  int getValue(int points) const;
};

#endif