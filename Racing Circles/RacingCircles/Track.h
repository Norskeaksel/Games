#pragma once
#include <FL/Fl_Widget.H>
#include <utility>
#include <vector>
#include "utilities.h"
#include <FL/fl_draw.H>
extern double w, h;
#define all(v) (v).begin(),(v).end()

class Track : public Fl_Widget {
public:
	std::vector < std::pair<double, double>> goals;
	vector<Obstacle>obs;
	Track() :Fl_Widget(100, 100, 100, 100) {
		vector<pair<double, double >> part2;
		double r = ::h / 2;
		goals = circlePoints({ ::w - r,r }, -(r- tweak));
		part2 = circlePoints({ r, r }, r - tweak);
		reverse(all(part2));
		goals.insert(goals.end(), all(part2));
		obs = generateObs(goals);
	}
	void draw() override{
		for(int i=0;i<goals.size();i++){
			fl_color(FL_DARK_GREEN);
			double x = goals[i].first;
			double y = goals[i].second;
			fl_circle(x, y, tweak);
		}
		for(int i=0;i<obs.size();i++){
			Obstacle a = obs[i];
			fl_color(a.color);
			fl_circle(a.x, a.y, a.r);
		}
	}
};
