#pragma once
#include <utility>
#include <vector>
#include <FL/Enumerations.H>

const int vehRad = 15;
const int tweak = 44;
using namespace std;
const int spillRad = 20;
const int boostRad = 15;
const int pillarRad = 5;
struct Obstacle {
	int x;
	int y;
	int r;
	Fl_Color color;
};
struct PhysicsState {
	double x;
	double y;
	double angle;
	double vel;
	double grip = 1;
};

pair<double, double> driveAlgorithm(PhysicsState ps, int power, int stop, int right, int left);
void mySteering(PhysicsState &ps, pair<double, double>temp);
void dontGo(PhysicsState &ps);
vector<pair<double, double>>circlePoints(pair<int, int>centre, double radius);
bool circleCollision(double delX, double delY, double sumR);
void offTrack(PhysicsState &ps, vector<pair<double, double>> goals);
vector<Obstacle> generateObs(vector<pair<double, double >>goals);
void collision(PhysicsState &ps, vector<Obstacle>obs);
bool moveAI(PhysicsState &AI, std::pair<double, double> currentGoal);