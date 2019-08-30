#pragma once
#include <iostream>
using namespace std;
enum Tile { EMPTY = 0, RED, YELLOW };
const int ROWS = 6;
const int COLS = 7;
using Board = Tile[ROWS][COLS];

bool isFull(Board board, int col);
ostream& operator<<(ostream& o, Tile t);
ostream& operator<<(ostream& o, Board b);
int findLowestPlace(Board b, int c);
int put(Board b, int c, Tile t);
bool isOutOfBounds(int r, int c);
int countTiles(Board b, int r, int c, int dr, int dc, Tile t);
bool xInARow(Board b, int r, int c, int x, Tile t);
bool victory(Board b, Tile t);