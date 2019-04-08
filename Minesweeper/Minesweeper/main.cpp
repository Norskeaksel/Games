#include "MinesweeperWindow.h"
#include <Graph.h>
#include <Window.h>

int main(){
	srand(time(NULL));
	int width=10, height=10, mines=10;
	cout << "Welcome to Minesweeper!\n";
	//Sleep(2000);
	cout << "In order to win you most open the last tile, not flagg it. Remember that and lets get started!\n";
	//Sleep(3500);
	cout<<"Choose a width (a number between 6 and 42 is recommended): ";
	cin >> width;
	cout << "\nChoose a height (a number between 1 and 19 is recommended): ";
	cin >> height;
	cout << "\nChoose the number of mines (a number between 0 and "<<height*width-1 <<" is recommended): ";
	cin>> mines;

	Point startPoint{ 0,0 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();

}
