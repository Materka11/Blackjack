#include "Hand.h"

Hand::Hand()
{
  addCard();
  addCard();
}

Hand::Hand(bool isDealer)
{
  addCard(isDealer);
  addCard();
}

void Hand::addCard(bool isDealer) {}

void Hand::hit() {}

void Hand::stand() {}

void Hand::doubleDown() {}

void Hand::surrender() {}

void Hand::getPoints() {}
