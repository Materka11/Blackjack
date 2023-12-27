#include "BlackjackGame.h"
#include <iostream>


BlackjackGame::BlackjackGame() : deck(), playerHand(deck, false), dealerHand(deck, true) {}

void BlackjackGame::startGame() {
    playerHand.getCards();
    dealerHand.getCards();
}

void BlackjackGame::resetGame() {
    deck.shuffle();
    playerHand.resetHand();
    dealerHand.resetHand();
    playerHand.addCard();
    playerHand.addCard();
    dealerHand.addCard();
    startGame();
}


void BlackjackGame::hit() {
	playerHand.addCard();
    playerHand.getCards();
    dealerHand.getCards();

    const int playerPoints = playerHand.getPoints();

    if (playerPoints == 21) {
       std::cout << "Gracz wygral" << std::endl;
    }
    else if (playerPoints > 21) {
       std::cout << "Krupier wygral" << std::endl;
    }
    else {
        getChoice();
    }
}

void BlackjackGame::stand() {
    const int initialDealerPoints = dealerHand.getPoints();
    const int playerPoints = playerHand.getPoints();

    if (initialDealerPoints > playerPoints && initialDealerPoints <= 21) {
        std::cout << "Krupier wygral" << std::endl;
    }
    else {
        while (dealerHand.getPoints() <= playerPoints && dealerHand.getPoints() <= 21) {
            dealerHand.addCard();
            playerHand.getCards();
            dealerHand.getCards();
        }

        const int finalDealerPoints = dealerHand.getPoints();

        if (finalDealerPoints > 21) {
            std::cout << "Gracz wygral" << std::endl;
        }
        else if (finalDealerPoints > playerPoints) {
            std::cout << "Krupier wygral" << std::endl;
        }
        else if (finalDealerPoints == playerPoints) {
            std::cout << "Remis" << std::endl;
        }
    }
}

void BlackjackGame::surrender() {
	std::cout << "Krupier wygral" << std::endl;
}

void BlackjackGame::getChoice() {
    std::string choice;

    std::cout << "Wpisz jedna w ponizszych komend:" << std::endl;
    std::cout << "hit" << std::endl;
    std::cout << "stand" << std::endl;
    std::cout << "reset" << std::endl << std::endl;
    std::cin >> choice;

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
        std::cout << "Nie poprawa komenda. Prosze sprobowac ponowne" << std::endl;
        getChoice();
    }
}

void BlackjackGame::playAgain() {
    char choice;

    std::cout << "Czy chcesz zagrać ponownie? (t/n): " << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 't': 
        resetGame();
        playAgain();
        break;
    case 'n': 
        std::cout << "Dziekujemy za gre" << std::endl;
        break;
    default:
        std::cout << "Niepoprawna komenda" << std::endl;
        playAgain();
        break;
    }
}

std::vector<std::pair<char, std::string>> BlackjackGame::getCards(bool isPlayer) {
    if (isPlayer) {
        return playerHand.getCards();
    }
    else {
        return dealerHand.getCards();
    }
}

int BlackjackGame::getPoints(bool isPlayer) {
    if (isPlayer) {
        return playerHand.getPoints();
    }
    else {
        return dealerHand.getPoints();
    }
}