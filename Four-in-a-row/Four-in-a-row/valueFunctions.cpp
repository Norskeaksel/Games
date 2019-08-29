#include <algorithm>
#include "valueFunctions.h"
#include <vector>

int counterValue(Board b, Tile t = RED) {
	int ans = 0;
	for (int c = 0; c < COLS; c++) {
		int row = put(b, c, t);
		//cout << b << endl;
		if (row == -1)
			continue;
		else {
			if (xInARow(b, row, c, 2))
				ans -= 2;
			if (xInARow(b, row, c, 3))
				ans -= 5;
			if (xInARow(b, row, c, 4))
				ans -= 100;
		}
		b[row][c] = EMPTY;
	}
	return ans;
}
int value(Board b, int col, Tile t = YELLOW) {
	int ans = 0;
	if (col == 3)
		ans += 4;
	int row = put(b, col, t);
	if (row == -1)
		ans = -1000;
	else {
		if (xInARow(b, row, col, 2))
			ans += 2;
		if (xInARow(b, row, col, 3))
			ans += 5;
		if (xInARow(b, row, col, 4))
			ans += 1000;
		ans += counterValue(b);
	}
	b[row][col] = EMPTY;
	return ans;
}

int chooseMove(Board b) {
	vector<int> scores(7,-1000);
	int move;
	do {
		move = rand() % COLS;
	} while (findLowestPlace(b, move) == -1);
	for (int c = 0; c < 7; c++) {
		scores[c] = value(b, c);
	}
	int score = -100;
	for(int i=0;i<7;i++){
		if(scores[i]>score&&findLowestPlace(b,i)!=-1){
			score = scores[i];
			move = i;
		}
	}
	return move;
}