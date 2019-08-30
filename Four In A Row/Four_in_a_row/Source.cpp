#include "utilities.h"
#include "playGame.h"

int main() {
	char a = 'y';
	while (a == 'y'){
		play();
		cout << "\nWanna play again? (y/n): ";
		cin >> a;
	}
}
