#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
  char cardRank;
  std::string cardSuit;

public:
  Card();
  Card(char rank, std::string suit);
  int getValue(int points) const;
  char getRank() const;
  std::string getSuit() const;
};

#endif