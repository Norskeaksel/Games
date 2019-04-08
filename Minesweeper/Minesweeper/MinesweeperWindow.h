#pragma once
#include "Window.h"
#include "Tile.h"

using namespace Graph_lib;
enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; //

// Minesweeper GUI
class MinesweeperWindow : Graph_lib::Window
{
public:
	//st�rrelsen til hver rute
	static constexpr int cellSize = 30;
	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);
	static void trueRestart(Address, Address pw){
		auto&win = reference_to<MinesweeperWindow>(pw);
		MinesweeperWindow *new_win = new MinesweeperWindow({ win.x_root(),win.y_root() }, win.width, win.height, win.mines, "Minesweeper");
		win.hide();
		copy_n((char*)new_win, sizeof(MinesweeperWindow), (char*)&win);
		//Her overskriver vi dataen til v�rt game vindu med data fra et ferskt vindu.
	}
	static void trueQuit(Address, Address pw){
		exit(0);
	}

private:
	Text minesLeft;
	const int width;//width i miner 
	const int height;//heigth i miner
	const int mines;//Antall miner
	int remainingTiles= width* height- mines;
	int gameLost = 0;
	Button restart;
	Button quit;
	Vector_ref<Tile> tiles; // Vektor som inneholder alle tiles
	Graph_lib::Rectangle rec;
	//Height og Width i piksler
	int Height() const { return height * cellSize; }
	int Width() const { return width * cellSize; }

	// F� en liste med naborutene rundt en tile
	vector<Point> adjacentPoints(Point xy) const;
	//tell miner basert p� liste
	int countMines(vector<Point> coords) const;

	//Sjekk at punkt er p� brettet og gj�r det til Tile
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x < Width() && xy.y >= 0 && xy.y < Height(); }
	Tile& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const Tile& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	//�pne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	//callback funksjon for tile knappen
	static void cb_click(Address, Address pw);
	
};
