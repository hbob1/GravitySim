#pragma once
#include <vector>
#include "body.h"
#include <cmath>

#define X 0
#define Y 1

class Sim {
private:
    std::vector<body>& bodies;
    double G;
    double deltaTime;

    std::vector<double> getDis(std::vector<double> pos1, std::vector<double> pos2);
    std::vector<double> getForce(std::vector<double> dis, double mass1, double mass2);

public:
    Sim(double dt, double g, std::vector<body>& bodiesList) :
        deltaTime(dt), G(g), bodies(bodiesList) {}

    void update(double deltaTime);

};