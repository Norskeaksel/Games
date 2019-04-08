#include "utilities.h"
#include "Vehicle.h"
#include <FL/Fl.H>
#include <conio.h>
#include <algorithm>
#define all(v) (v).begin(),(v).end()
std::pair<double, double> driveAlgorithm(PhysicsState ps, int power, int stop, int right, int left) {
	const int bound = 2;
	const double speed = bound;
	const double steering = bound;
	double velAcc = 0;
	double angAcc = 0;
	if (Fl::event_key(power)) {
		velAcc = speed;
	}
	if (Fl::event_key(right)) {
		angAcc = steering;
	}

	if (Fl::event_key(stop)) {
		velAcc -= speed;
	}
	if (Fl::event_key(left)) {
		angAcc = -steering;
	}
	velAcc = min(velAcc, bound);
	velAcc = max(velAcc, -1 * bound);
	angAcc = min(angAcc, bound);
	angAcc = max(angAcc, -1 * bound);
	return { velAcc ,angAcc };
}

void dontGo(PhysicsState &ps) {
	if (ps.x <= 0 + vehRad)
		ps.x = vehRad;
	if (ps.y <= 0 + vehRad)
		ps.y = vehRad;
	if (ps.x >= ::w - vehRad)
		ps.x = ::w - vehRad;
	if (ps.y >= ::h - vehRad)
		ps.y = ::h - vehRad;
}

vector<pair<double, double>> circlePoints(pair<int, int> xy, double r) {
	vector<pair<double, double>>goals;
	double pi = acos(-1);
	double theta = pi / 2;
	double x = xy.first + r;
	double y = xy.second;
	while (theta < 2 * pi + pi / 2) {
		theta += pi / 100;
		x = xy.first + r * sin(theta);
		y = xy.second + r * cos(theta);
		goals.push_back({ x,y });
	}
	return goals;
}
void mySteering(PhysicsState &ps, pair<double, double>temp) {
	int bound = 2;
	double velAcc = min(temp.first, bound);
	velAcc = max(velAcc, -1 * bound);
	double angAcc = min(temp.second, bound);
	angAcc = max(angAcc, -1 * bound);
	ps.grip += 0.01*(1 - ps.grip);
	ps.vel += 0.006 * ps.grip * velAcc * (6 - abs(ps.vel) + 5 * ((ps.vel > 0) != (velAcc > 0)));
	ps.vel = max(ps.vel, -1.5);
	ps.angle += 0.03 * ps.grip * angAcc;
	ps.x += ps.vel * cos(ps.angle);
	ps.y += ps.vel * sin(ps.angle);
}
bool circleCollision(double delX, double delY, double sumR) {
	return delX * delX + delY * delY < sumR*sumR;
}

void offTrack(PhysicsState& ps, vector<pair<double, double>> goals) {
	for (int i = 0; i < goals.size(); i++) {
		double delX = goals[i].first - ps.x;
		double delY = goals[i].second - ps.y;
		double sumR = (vehRad + tweak) / 1.8;
		if (circleCollision(delX, delY, sumR))
			return;
	}
	ps.vel *= 0.95;//friction
}

vector<Obstacle> generateObs(vector<pair<double, double >>goals) {
	vector<Obstacle> obs;
	for (int i = 0; i < goals.size(); i++) {
		Obstacle a = { goals[i].first,goals[i].second };
		int ran = rand() % 100;
		switch (ran) {
		case 1:
			a.r = spillRad;
			a.color = FL_GRAY;
			break;
		case 2:
			a.r = boostRad;
			a.color = FL_RED;
			break;
		case 3:
			a.r = pillarRad;
			a.color = FL_YELLOW;
			break;
		default:
			continue;
		}
		obs.push_back(a);
	}
	sort(all(obs), [](Obstacle a, Obstacle b) {return a.r > b.r; });
	return obs;
}

void collision(PhysicsState& ps, vector<Obstacle>obs) {
	for (int i = 0; i < obs.size(); i++) {
		Obstacle a = obs[i];
		double delX = ps.x - a.x;
		double delY = ps.y - a.y;
		double sumR = vehRad + a.r;
		if (circleCollision(delX, delY, sumR)) {
			if (a.r == spillRad)
				ps.grip = 0.05;
			else if (a.r == boostRad) {
				ps.grip = 2;
				ps.vel += 0.5;
			}
			else if (a.r == pillarRad)
				ps.vel = -0.5;
		}
	}
}

bool moveAI(PhysicsState &AI, std::pair<double, double> currentGoal) {
	const double delX = currentGoal.first - AI.x;
	const double delY = currentGoal.second - AI.y;
	if (circleCollision(delX, delY, vehRad)) {
		return true;
	}
	else {
		const double dist = sqrt(delX * delX + delY * delY);
		AI.x += delX / dist * 5.5;
		AI.y += delY / dist * 5.5;
	}
	return false;
}
