#include "utilities.h"
#include "valueFunctions.h"
bool playerTurn(Board b, Tile t = RED) {
	cout << endl << "Board state:\n" << b << endl << "Choose column ";
	int col = -1;
	while (col < 0 || col >= COLS) {
		cout << ":";
		cin >> col;
	}
	int row = findLowestPlace(b, col);
	put(b, col, t);
	return xInARow(b, row, col,4);
}

bool machineTurn(Board b, int choice, Tile t = YELLOW) {
	if (choice == 2) {
		playerTurn(b, t);
	}
	else {
		int col=chooseMove(b);
		int row = findLowestPlace(b, col);
		put(b, col, t);
		return xInARow(b, row, col,4);
	}
}

void play(){
	cout << "Welcome to 4 in a row! Press 1 to play against the computer and 2 to play against another player: ";
	int choice;
	cin >> choice;
	cout << endl;
	Board b;
	int sum = ROWS * COLS;
	for (auto& y : b)
		for (auto& x : y)
			x = EMPTY;
	while (sum -= 2) {
		if (playerTurn(b)) {
			if (choice == 2)
				cout << "Player1 wins!\n";
			else
				cout << b << "\nYou won!\n";
			break;
		}
		if (machineTurn(b, choice)) {
			if (choice == 2)
				cout << "Player2 wins!\n";
			else
				cout << b << "\nYou lose\n";
			break;
		}
	}
	if (sum == -2)
		cout << "It's a draw\n";
}