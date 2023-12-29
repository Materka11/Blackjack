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
}

GameResult BlackjackGame::stand() {
    const int initialDealerPoints = dealerHand.getPoints();
    const int playerPoints = playerHand.getPoints();

    if (initialDealerPoints > playerPoints && initialDealerPoints <= 21) {
        return DEALER;
    }
    else {
        while (dealerHand.getPoints() <= playerPoints && dealerHand.getPoints() <= 21) {
            dealerHand.addCard();
            playerHand.getCards();
            dealerHand.getCards();
        }

        const int finalDealerPoints = dealerHand.getPoints();

        if (finalDealerPoints > 21) {
            return PLAYER;
        }
        else if (finalDealerPoints > playerPoints) {
            return DEALER;
        }
        else if (finalDealerPoints == playerPoints) {
            return DRAW;
        }
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