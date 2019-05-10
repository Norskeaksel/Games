#include <iostream>
#include "utilities.h"
using namespace std;
void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}
void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = v0 + 1;
	//int *p=&increment
	incrementByValueNumTimes2(&result, increment, iterations); //minneadressen result henter ut verdien som pekes på 
	std::cout << "v0: " << v0								//av pekeren i den orginale funskjonen, mens de increment
		<< " increment: " << increment						//og iterations tar inn verdiene 2 og 10
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}
void testTablesSorting() {
	int storrelse = 20;
	int percentages[20];
	randomizeArray(percentages, storrelse);
	swapNumbers(&percentages[1], &percentages[2]);
	printArray(percentages, storrelse);
	cout << endl;
	//swapNumbers(&percentages[0], &percentages[1]);
	//printArray(percentages, storrelse);
	sortArray(percentages, storrelse);
	cout << endl;
	printArray(percentages, storrelse);
	cout << endl;
	cout << medianOfArray(percentages, storrelse);
	cout << endl;
}
void testCStrings() {
	int antall = 9;
	char grades[9];
	randomizeCString(grades, antall);
	cout << grades << endl;
	int gradeCount[6];
	for (int i = 0; i < 6; i++) {
		char tegn = 'A' + i;
		gradeCount[i] = countOccurencesOfCharacter(grades, 6, tegn);
	}
	printArray(gradeCount, 6);
	cout << endl;
	double gjennomsnitt = 0;
	for (int j = 0; j < 6; j++) {
		gjennomsnitt += gradeCount[j] * (1 + j);
		if (j == 5) {
			cout << gjennomsnitt / 6 << endl;
		}
	}
}
