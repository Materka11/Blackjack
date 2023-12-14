#include <iostream>
#include "Blackjack.h"

using namespace std;

void handleGame(Blackjack& game) {
    string choice;

    cout << "Wpisz start, zeby zaczac gre. Gra #sz?" << endl;
    cin >> choice;

    if (choice == "start") {
        cout << "Gra rozpoczeta" << endl << endl;
        game.startGame();
        game.playAgain();
    }
    else {
        cout << "Niepoprawna komenda" << endl;
        handleGame(game);
    }
}


int main() {
  Blackjack game;
  handleGame(game);
  return 0;
}