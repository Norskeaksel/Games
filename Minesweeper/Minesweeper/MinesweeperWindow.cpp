#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, height*cellSize+80, title), width(width), height(height),
mines(mines),
minesLeft({5,height*cellSize+30},"Mines left: "+to_string(mines)),
restart({ 0,height*cellSize + 35 }, width * cellSize / 2, 50, "Restart", trueRestart),
quit({ width * cellSize/2,height*cellSize + 35 }, width * cellSize/2,50, "Quit", trueQuit),
rec({ 0, height*cellSize}, { width* cellSize ,height*cellSize + 35 })
{
	rec.set_fill_color(Color::gray);
	attach(rec);
	attach(quit);
	attach(restart);
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
	minesLeft.set_font_size(30);
	minesLeft.set_color(Color::black);
	attach(minesLeft);
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i * cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner på tilfeldige posisjoner
	while (mines--){
		int pos = rand() % (height*width);
		if (tiles[pos].isMine)
			mines++;
		else
			tiles[pos].isMine = true;
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int counter = 0;
	for(Point p:points)
		counter += at(p).isMine;
	return counter;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).state == Cell::closed) {
		Tile& tile = at(xy);
		tile.open();
		if(tile.isMine){
			gameLost = 1;
			Text *gameOver=new Text(Point{ cellSize / 2, cellSize*2 }, "Game over!");
			gameOver->set_font_size(50);
			gameOver->set_color(Color::dark_red);
			attach(*gameOver);
			for(int x=0;x<width;x++){
				for(int y=0;y<height;y++){
					Point xy = { x *cellSize,y*cellSize };
					Tile&t = at(xy);
					if (t.isMine)
						t.open();
					else
						openTile(xy);
				}
			}
			tile.set_label_color(Color::red);
			return;
		}
		else{
			remainingTiles--;
			if(remainingTiles==0&&gameLost==0){
				Text *gameWon = new Text(Point{ cellSize, cellSize * 2 }, "Victory!");
				gameWon->set_color(Color::dark_magenta);
				gameWon->set_font_size(50);
				attach(*gameWon);
			}
			vector<Point>ap = adjacentPoints(xy);
			int cm= countMines(ap);
			if (cm == 0)
				for (auto p : ap)
					openTile(p);
			else
				tile.setAdjMines(cm);
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if(at(xy).state!=Cell::open)
		at(xy).flag();
	int flags = 0;
	for(auto t:tiles){
		flags += t->state == Cell::flagged;
	}
	minesLeft.set_label("Mines left: "+to_string(mines-flags));
}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}
