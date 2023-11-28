#include <iostream>
#include <string>

using namespace std;

class Card
{
private:
  char cardRank;
  string cardSuit;

public:
  Card() : cardRank(' '), cardSuit("") {}
  Card(char rank, string suit) : cardRank(rank), cardSuit(suit) {}

  int getValue(int points) const
  {
    if (cardRank >= '2' && cardRank <= '9')
    {
      return cardRank - '0';
    }
    if (cardRank == 'T' || cardRank == 'J' || cardRank == 'Q' || cardRank == 'K')
    {
      return 10;
    }
    if (cardRank == 'A' && points + 11 <= 21)
    {
      return 11;
    }
    else
    {
      return 1;
    }
  }
};

class Deck
{
private:
  char cardsRank[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  string cardsSuit[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};

  int CARDS_RANK_LENGHT = sizeof(cardsRank) / sizeof(cardsRank[0]);
  int CARDS_SUIT_LENGHT = sizeof(cardsSuit) / sizeof(cardsSuit[0]);

  Card deck[52];

public:
  Deck()
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

  void shuffle()
  {
  }
};

class Hand
{
public:
  void addCard(bool isCroupier)
  {
  }

  void hit()
  {
  }

  void stand()
  {
  }

  void doubleDown()
  {
  }

  void surrender()
  {
  }
};

class BlackJack
{
};
