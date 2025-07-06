#include "drawer.h"

static double scaleFactor = 1.0;

void setScale(double scale) {
    scaleFactor = scale;
}

void addToArray(std::vector<body>& bodies, double mass, std::vector<double> pos, std::vector<double> vel, 
    int color[3], sf::CircleShape shape) {
    body newBody;
    newBody.mass = mass;
    newBody.pos = pos;
    newBody.vel = vel;
    newBody.color[0] = color[0];
    newBody.color[1] = color[1];
    newBody.color[2] = color[2];
    newBody.shape = shape;

    bodies.push_back(newBody);
}

void drawBodies(sf::RenderWindow& window, std::vector<body>& bodies, double deltaTime) {
    for (auto& b : bodies) {

        sf::Vector2f newPos(static_cast<float>((b.pos[0] + b.vel[0] * deltaTime) / scaleFactor),
         static_cast<float>((b.pos[1] + b.vel[1] * deltaTime) / scaleFactor));
         
        b.shape.setPosition(newPos);
        b.shape.setFillColor(sf::Color(b.color[0], b.color[1], b.color[2]));
        
        window.draw(b.shape);
    }
}