#pragma once
#include <vector>
#include "body.h"

void addToArray(std::vector<body>& bodies, double mass, std::vector<double> pos, std::vector<double> vel, 
    int color[3], sf::CircleShape shape);

void drawBodies(sf::RenderWindow& window, std::vector<body>& bodies, double deltaTime);

void setScale(double scale);