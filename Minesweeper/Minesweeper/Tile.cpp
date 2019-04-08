#include "Tile.h"
// For å sette labelfarge i henhold til hvor mange miner som er rundt
Color minesToColor[9]{ Color::black,Color::blue,
									Color::dark_red,
									Color::dark_green,
									Color::dark_magenta,
									Color::dark_blue,
									Color::dark_cyan,
									Color::red,
									Color::dark_yellow };

// For å sette Tilelabel i henhold til state
map<Cell, string> cellToSymbol{ {Cell::closed, ""},
								 {Cell::open, ""},
								 {Cell::flagged, "@<"} };

void Tile::open() {
	static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket på, tilsvarer åpnet rute
	if (state != Cell::flagged)
		state = Cell::open;
	if (isMine) {
		set_label("X");
		set_label_color(Color::black);
	}
}

void Tile::flag() {
	if (state == Cell::flagged) {
		state = Cell::closed;
		string label = cellToSymbol[state];
		set_label(label);
	}
	else {
		state = Cell::flagged;
		set_label(cellToSymbol[state]);
		set_label_color(Color::blue);
	}
}

void Tile::setAdjMines(int n){
	set_label(to_string(n));
	set_label_color(minesToColor[n]);
}
