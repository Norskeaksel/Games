#include <iostream>
using namespace std;
enum Tile { EMPTY = 0, RED, YELLOW };

const int ROWS = 6;
const int COLS = 7;

using Board = Tile[ROWS][COLS];

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
int findLowestPlace(Board b, int c){
	for(int i = ROWS - 1;i>=0;i--){
		if (b[i][c] == EMPTY)
			return i;
	}
	return -1;
}
int put(Board b, int c, Tile t){
	int row = findLowestPlace(b, c);
	if (row == -1)
		return row;
	b[row][c] = t;
	return row;
}
bool isOutOfBounds(int r, int c){
	return !(r >= 0 && r < ROWS && c >= 0 && c < COLS);
}
int countTiles(Board b, int r, int c, int dr, int dc){
	int sum = 0;
	Tile t = b[r][c];
	while(!isOutOfBounds(r,c)){
		if (b[r][c] != t)
			return sum;
		sum++;
		r += dr;
		c += dc;
	}
	return sum;
}
bool fourInARow(Board b, int r, int c){
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i==0&&j==0) continue;
			if (countTiles(b, r, c, i, j) >= 4)
				return 1;
		}
	}
	return 0;
}
bool playerTurn(Board b,Tile t=RED){
	cout <<endl<< b<<endl<<"Place piece in column ";
	int col=-1;
	while(col<0||col>=COLS){
		cout << ":";
		cin >> col;
	}
	int row = findLowestPlace(b, col);
	put(b, col, t);
	return fourInARow(b, row, col);
}
bool machineTurn(Board b, Tile t = YELLOW){
	int col;
	do {
		col = rand() % COLS;
	} while (findLowestPlace(b, col)==-1);
	int row = findLowestPlace(b, col);
	put(b, col, t);
	return fourInARow(b, row, col);
}

int main() {
	Board b;
	int sum = ROWS * COLS;
	for (auto& y : b)
		for (auto& x : y)
			x = EMPTY;
	while(sum-=2){
		if (playerTurn(b)) {
			cout <<b<< "\nYou won!\n";
			break;
		}
		if(machineTurn(b)){
			cout << b<<"\nYou lose\n";
			break;
		}
	}
	if (sum == -2)
		cout << "It's a draw\n";
}
