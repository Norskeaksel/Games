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
	cout << "Skriv 4 bokstaver mellom A og F. Du skal gjette hvilke bokstaver jeg har valgt :)\nFør HVER gjetning må du trykke på next og deretter trykke i konsollvinduet der du skriver inn bokstavene";
	playMastermind();
}

/*struct TemperatureMeasurment {
double tempratur;
int tid;
};
void printTemprature(TemperatureMeasurment* tm) {
cout << "Temperature: " << tm->tempratur << endl
<< "Time: " << tm->tid << "\n";
}
int main() {
TemperatureMeasurment tm = { 23.6,12 };
printTemprature(&tm);
cout << "---\n";
printTemprature(&tm);
}
appropo pekere: int* apter lager en peker med a sin minneadresse. For å få ut verdien til denne minneadrssen
brukes &aptr*/
