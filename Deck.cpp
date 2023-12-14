#include "Deck.h"
#include <iostream>
#include <random>

Deck::Deck() : CARDS_RANK_LENGHT(13), CARDS_SUIT_LENGHT(4) {
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

void Deck::shuffle() {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52; 

        Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

Card Deck::getRandomCard() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 51);
    int randomIndex = distribution(gen);
    return deck[randomIndex];
}

