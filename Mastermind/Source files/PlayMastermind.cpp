#include <iostream>
#include "Utilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "masterVisual.h"
using namespace std;
void playMastermind() {
	MastermindWindow mwin{ Point{900, 20}, 400, 600, "Mastermind" };
	int SIZE = 4;
	int LETTERS = 6;
	char code[5];
	char guess[5];
	randomizeCString(code, LETTERS - 1);
	int riktige = 0,nesten=0;
	int round = 0;
	addGuess(mwin, code, SIZE, 'A', round);
	hideCode(mwin, SIZE);
	do
	{
		//mwin.wait_for_button();
		Fl::wait();
		Fl::redraw();
		round++;
		cout << "forsøk " << round << " av 5" << endl;
		readInputToCString(guess, SIZE, 'A', 'F');
		cout << "Antall riktige bokstaver på rett posisjon" << endl;
		riktige = checkCharactersAndPosition(code, guess);
		nesten = checkCharacters(code, guess);
		for (int i = 0; i < 4; i++) {
			addGuess(mwin, guess, SIZE, 'A', round);
			addFeedback(mwin, riktige, nesten, SIZE, round);
		}

		cout << riktige << endl;
		cout << "Antall riktige bokstaver på feil posisjon" << endl;
		cout << checkCharacters(code, guess) - riktige << endl;

	} while (riktige < SIZE && round < 5);
	if (round < 6 && riktige == SIZE) {
		cout << "Gratulerer, du vant!" << endl << "Det var " << code << " som var koden" << endl;

	}
	else{
		cout << "Desverre, du tapte :(" << endl << "Det var " << code << " som var koden" << endl;
	}
	for (int i = 0; i < 4; i++) {
		addGuess(mwin, guess, SIZE, 'A', round);
		addFeedback(mwin, riktige, nesten, SIZE, round);
	}
	cout << "Har du lyst til å spille igjen? y/n" << endl;
	char x;
	cin >> x;
	switch (tolower(x)) {
	case 'y':
		playMastermind();
		break;
	case 'n':
		cout << "Neivel" << endl;
		break;
	default:
		cout << "Tar det som et nei" << endl;
		break;

	}
}
