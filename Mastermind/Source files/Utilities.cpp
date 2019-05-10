#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
int randomWithLimits(int a, int b) {
	srand(std::time(nullptr));
	for (int i = 0; i < 100; i++)  rand();
	int tilfeldig_tall = rand() % 900 + 101;
	return tilfeldig_tall;
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimes2(int* startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment; //ved å bruke en peker så vil andre funksjoner kunne bruke verdien til startvalue
	}								//med å bruke &startValue
	//cout << *startValue << endl;
}
void swapNumbers(int* a, int* b) {
	int c = *b; //må sette en midlertidig variabel c lik pekeren b. Pekere er nødvendig for at andre funksjoner 
	*b = *a; //skal kunne se at variablene er byttet.
	*a = c;
}
void printArray(int minarray[], int antall) {
	for (int i = 0; i < antall; i++) {
		cout << minarray[i] << " ";
	}
}
void randomizeArray(int tabell[], int storrelse) {
	for (int i = 0; i < storrelse; i++) {
		tabell[i] = rand() % (100 + 1);
	}
}
void sortArray(int tabell[], int storrelse) {
	for (int i = 0; i < storrelse; i++) {
		for (int j = 0; j < storrelse; j++) {
			if (tabell[j] > tabell[i]) {
				swapNumbers(&tabell[j], &tabell[i]);
			}
		}
	}

}
double medianOfArray(int sortert[], int storrelse) {
	if (storrelse % 2 == 1) {
		return sortert[storrelse / 2];
	}
	else {
		return (sortert[storrelse / 2 - 1] + sortert[storrelse / 2]) / 2.0; //returnerer ikke flytall?
	}
}
void randomizeCString(char grades[], int storrelse) {
	for (int i = 0; i < storrelse - 1; i++) {
		grades[i] = 'A' + rand() % 6;
	}
	grades[storrelse - 1] = '\0';
}
void readInputToCString(char tabell[], int antall, int bunn, int top) {
	char karakter;
	int bad;
	do {
		string input;
		cin >> input;
		bad = 0;
		for (int i = 0; i < antall; i++) {
			karakter = input[i];
			karakter = toupper(karakter);
			if (karakter > top || karakter < bunn || input.size() != 4) {
				cout << "Ugyldig input. Prøv igjen" << endl;
				bad = 1;
				break;
			}
			tabell[i] = karakter;
		}
	} while (bad);
}
int countOccurencesOfCharacter(char cstreng[], int antall, char tegn) {
	int forekomster = 0;
	for (int i = 0; i < antall; ++i) {
		if (tegn == cstreng[i]) {
			forekomster++;
		}
	}
	return forekomster;
}
int checkCharactersAndPosition(char code[], char guess[]) {
	int rett = 0;
	for (int i = 0; i < 4; i++) {
		if (guess[i] == code[i]) {
			rett++;
		}
	}
	return rett;
}
int checkCharacters(char code[], char guess[]) {
	int count = 0;
	char Bokstaver[7] = { 'A','B','C','D','E','F' };
	for (int i = 0; i < 6; i++) {
		int icode = countOccurencesOfCharacter(code, 4, Bokstaver[i]);
		int iguess = countOccurencesOfCharacter(guess, 4, Bokstaver[i]);
		count += min(icode, iguess);
	}
	return count;
}
