#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand
{
private:
  std::vector<Card> cards;

public:
  Hand();
  Hand(bool isDealer);
  void addCard(bool isDealer = false);
  void hit();
  void stand();
  void doubleDown();
  void surrender();
  void getPoints();
};

#endif