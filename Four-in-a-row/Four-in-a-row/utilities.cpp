#include "utilities.h"

bool isFull(Board board, int col) {
	return board[0][col] != EMPTY;
}
ostream& operator<<(ostream& o, Tile t) {
	if (t == 0)
		o << '*';
	if (t == 1)
		o << 'R';
	if (t == 2)
		o << 'Y';
	return o;
}
ostream& operator<<(ostream& o, Board b) {
	for (int y = 0; y < ROWS; y++) {
		for (int x = 0; x < COLS; x++)
			cout << b[y][x] << " ";
		cout << endl;
	}
	return o;
}
int findLowestPlace(Board b, int c) {
	for (int i = ROWS - 1; i >= 0; i--) {
		if (b[i][c] == EMPTY)
			return i;
	}
	return -1;
}
int put(Board b, int c, Tile t) {
	int row = findLowestPlace(b, c);
	if (row == -1)
		return row;
	b[row][c] = t;
	return row;
}
bool isOutOfBounds(int r, int c) {
	return !(r >= 0 && r < ROWS && c >= 0 && c < COLS);
}
int countTiles(Board b, int r, int c, int dr, int dc, Tile t) {
	int sum = 0;
	while (!isOutOfBounds(r, c)) {
		if (b[r][c] != t)
			return sum;
		sum++;
		r += dr;
		c += dc;
	}
	return sum;
}
bool xInARow(Board b, int r, int c, int x, Tile t) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			if (countTiles(b, r, c, i, j, t) >= x)
				return 1;
		}
	}
	return 0;
}
bool victory(Board b, Tile t) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (i == 0 && j == 0) continue;
					if (countTiles(b, row, col, i, j, t) >= 4)
						return 1;
				}
			}
		}
	}
	return 0;
}
