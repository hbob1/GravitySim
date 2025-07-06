#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct body {
    double mass;
    std::vector<double> pos;
    std::vector<double> vel;
    int color[3];
    sf::CircleShape shape;

};
