#include <iostream>
#include "Utilities.h"
#include "test.h"
#include <ctime>
#include "playMastermind.h"
#include "masterVisual.h"
using namespace std;
//Verdien til v0 er 5
int main() {
	setlocale(LC_ALL, "norwegian");
	srand(std::time(nullptr));
	//testCallByValue();
	//testCallByPointer();
	int x = 1;
	int y = 2;
	swapNumbers(&x, &y);
	//testTablesSorting();
	//testCStrings();
	cout << "Skriv 4 bokstaver mellom A og F. Du skal gjette hvilke bokstaver jeg har valgt.\nStart med å trykke på next i grafikkvinduet.\nTrykk deretter i konsollvinduet og du er klar til å gjette koden :)\n";
	playMastermind();
}
