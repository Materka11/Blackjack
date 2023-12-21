#include "Blackjack.h"
#include <iostream>

using namespace std;

Blackjack::Blackjack() : deck(), playerHand(deck, false), dealerHand(deck, true) {}

void Blackjack::startGame() {
    playerHand.getCards();
    dealerHand.getCards();

    const int playerPoints = playerHand.getPoints();

    if (playerPoints == 21) {
        cout << "Gracz wygral" << endl;
    }
    else {
        getChoice();
    }
}

void Blackjack::resetGame() {
    deck.shuffle();
    playerHand.resetHand();
    dealerHand.resetHand();
    playerHand.addCard();
    playerHand.addCard();
    dealerHand.addCard();
    startGame();
}


void Blackjack::hit() {
	playerHand.addCard();
    playerHand.getCards();
    dealerHand.getCards();

    const int playerPoints = playerHand.getPoints();

    if (playerPoints == 21) {
       cout << "Gracz wygral" << endl;
    }
    else if (playerPoints > 21) {
       cout << "Krupier wygral" << endl;
    }
    else {
        getChoice();
    }
}

void Blackjack::stand() {
    const int initialDealerPoints = dealerHand.getPoints();
    const int playerPoints = playerHand.getPoints();

    if (initialDealerPoints > playerPoints && initialDealerPoints <= 21) {
        cout << "Krupier wygral" << endl;
    }
    else {
        while (dealerHand.getPoints() <= playerPoints && dealerHand.getPoints() <= 21) {
            dealerHand.addCard();
            playerHand.getCards();
            dealerHand.getCards();
        }

        const int finalDealerPoints = dealerHand.getPoints();

        if (finalDealerPoints > 21) {
            cout << "Gracz wygral" << endl;
        }
        else if (finalDealerPoints > playerPoints) {
            cout << "Krupier wygral" << endl;
        }
        else if (finalDealerPoints == playerPoints) {
            cout << "Remis" << endl;
        }
    }
}

void Blackjack::surrender() {
	cout << "Krupier wygral" << endl;
}

void Blackjack::getChoice() {
    string choice;

    cout << "Wpisz jedna w ponizszych komend:" << endl;
    cout << "hit" << endl;
    cout << "stand" << endl;
    cout << "reset" << endl << endl;
    cin >> choice;

    if (choice == "hit") {
        hit();
    }
    else if (choice == "stand") {
        stand();
    }
    else if (choice == "reset") {
        resetGame();
    }
    else {
        cout << "Nie poprawa komenda. Prosze sprobowac ponowne" << endl;
        getChoice();
    }
}

void Blackjack::playAgain() {
    char choice;

    cout << "Czy chcesz zagrać ponownie? (t/n): " << endl;
    cin >> choice;

    switch (choice)
    {
    case 't': 
        resetGame();
        playAgain();
        break;
    case 'n': 
        cout << "Dziekujemy za gre" << endl;
        break;
    default:
        cout << "Niepoprawna komenda" << endl;
        playAgain();
        break;
    }
}
