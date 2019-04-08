#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <FL/Fl_Double_Window.H>.
#include <FL/Fl_Widget.H>
#include "Vehicle.h"
#include <chrono>
#include <thread>
#include "Track.h"
#include <iostream>
#include <string>
//double w{ Fl::w()/1.0 }, h{ Fl::h()/1.1 };
double w = 1220, h = 650;
//to use these in other files, declare them first using extern double, then use ::w or ::h when you want to get their value

const int Up = FL_Up, Down = FL_Down, Right = FL_Right, Left = FL_Left;
int main() {
	srand(time(NULL));
	string p1 = "Player 1", p2 = "Player 2";
	bool IAI;
	cout << "Welcome to Racing Circles!\nYour objective is to drive into the checkpoints of the same color as yourself. It's first to 25.\nYou boost with the up arrow (or w), steer with the left and right key (a and d) and break with the down key (s).\nEnter the name of player 1: ";
	cin >> p1;
	cout << "\nEnter the name of player 2. If you don't want another player type '0', then enter: ";
	cin >> p2;
	cout << "\nDo you want to play against an AI? Enter '1' if you do and '0' if you don't: ";
	cin >> IAI;
	Fl_Double_Window *window = new Fl_Double_Window(w, h);
	window->color(FL_BLACK);
	Track t;
	Vehicle car1(FL_DARK_BLUE, h / 2, 30, driveAlgorithm, Up, Down, Right, Left, t, p1, IAI);
	if (p2 != "0") {
		Vehicle car2(FL_DARK_CYAN, h / 2, 40, driveAlgorithm, 'w', 's', 'd', 'a', t, p2);
		window->end();
		window->show();
		auto next = std::chrono::steady_clock::now();
		while (window->shown()) {
			Fl::check();
			Fl::redraw();
			std::this_thread::sleep_until(next);
			next += std::chrono::microseconds(100000 / 6);
		}
		return Fl::run();
	}
	else{
		window->end();
		window->show();
		auto next = std::chrono::steady_clock::now();
		while (window->shown()) {
			Fl::check();
			Fl::redraw();
			std::this_thread::sleep_until(next);
			next += std::chrono::microseconds(100000 / 6);
		}
		return Fl::run();
	}
}