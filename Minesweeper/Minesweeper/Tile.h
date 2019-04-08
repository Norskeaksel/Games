#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan være i
enum class Cell { closed, open, flagged };

struct Tile : Button
{
	Tile(Point pos, int size, Graph_lib::Callback cb, bool isMine=false)
		:Button(pos, size, size, "", cb),isMine(isMine) {};

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw(); }

	void open(); // Åpner ruten
	void flag();// Flagger en rute

	Cell state = Cell::closed;
	void setAdjMines(int n);
	bool isMine;
};