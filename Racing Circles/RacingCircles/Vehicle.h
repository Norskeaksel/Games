#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include "utilities.h"
#include <cmath>
#include "Track.h"
#include <FL/Fl_Box.H>
extern double w, h;

using namespace std;

class Vehicle : public Fl_Widget {
	const Fl_Color color;
	const int xStart;
	const int yStart;
	double velAcc = 0;
	double angAcc = 0;
	int power, stop, left, right;
	pair<double, double>(*driveAlgorithm)(PhysicsState, int, int, int, int);
	const Track &t;
	int index = 0;
	int points = 0;
	string player;
	bool includeAI;
	PhysicsState AI;
	int AIIndex = 350;
	int AIpoints = 0;
public:
	PhysicsState ps = { vehRad,vehRad,0,0,0 };
	Vehicle(const Fl_Color c, int x, int y
		, pair<double, double>(*dA)(PhysicsState, int, int, int, int)
		, int w, int s, int a, int d
		, Track &t
		, string p, bool IAI) :
		Fl_Widget(100, 100, 100, 100)
		, color(c), xStart(x), yStart(y)
		, power(w)
		, stop(s), left(a), right(d), driveAlgorithm(dA)
		, t(t)
		, player(p), includeAI(IAI)
	{
		ps.x = vehRad + xStart;
		ps.y = vehRad + yStart;
		AI.x = ps.x;
		AI.y = ps.y - 10;
	}
	void nextGoal() {
		double delX = t.goals[index].first - ps.x;
		double delY = t.goals[index].second - ps.y;
		double sumR = (vehRad + tweak);
		if (circleCollision(delX, delY, sumR)) {
			index += 50;
			points++;
		}
		if (index >= t.goals.size()) {
			index = 50;
		}
	}
	void handleAI(bool includeAI){
		if (includeAI) {
			fl_color(170);
			fl_circle(AI.x, AI.y, vehRad);
			if (moveAI(AI, t.goals[AIIndex])) {
				AIIndex++;
				if (AIIndex == t.goals.size())
					AIIndex = 0;
				if (AIIndex == 0)
					AIpoints++;
			}
		}
	}
	void victoryScreen(int points, int &AIpoints){
		if (points >= 25 || AIpoints >= 4) {
			fl_color(color);
			fl_font(fl_font(), 190);
			string victory = player + " wins!";
			if (AIpoints >= 4) {
				fl_color(170);
				victory = "The AI wins!";
				points = 0;
			}
			else{
				AIpoints = 0;
			}
			fl_draw(victory.c_str(), 10, 200);
		}
	}
	void draw() override {
		nextGoal();
		handleAI(includeAI);
		victoryScreen(points, AIpoints);
		fl_begin_polygon();
		fl_color(color);
		fl_circle(t.goals[index].first, t.goals[index].second, tweak/1.2);
		fl_circle(ps.x, ps.y, vehRad);


		pair<double, double>temp = driveAlgorithm(ps, power, stop, left, right);
		mySteering(ps, temp);
		offTrack(ps, t.goals);
		dontGo(ps);
		collision(ps, t.obs);
	}
};