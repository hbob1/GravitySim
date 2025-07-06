#include <SFML/Window.hpp>
#include <chrono>
#include "sim.h"
#include "drawer.h"

// F = G * (m1 * m2) / r^2

double G = 6.67430e-11;

std::vector<body> bodies;

double deltaTime(){
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - lastTime;
    lastTime = currentTime;
    return elapsed.count();
}

Sim sim (10, G, bodies);

int colorEarth[3] = {0, 0, 255};
int colorMoon[3] = {200, 200, 200};

double scale = 1e6; // 1,000,000 meters = 1 pixel

int offsetX = 800 * scale; // 800,000 meters
int offsetY = 600 * scale; // 600,000 meters

int main()
{

    setScale(scale); // 1,000,000 meters = 1 pixel

    addToArray(bodies, 5.97e24, {800e3 + offsetX, 600e3 + offsetY}, {0, 0}, colorEarth, sf::CircleShape(10));
    addToArray(bodies, 7.35e22, {800e3 + 384400e3 + offsetX, 600e3 + offsetY}, {0, 1022}, colorMoon, sf::CircleShape(4)); 

    sf::RenderWindow window(sf::VideoMode({1600, 1200}), "My window");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        double dt = deltaTime();
        sim.update(10);
        window.clear(sf::Color::Black);
        drawBodies(window, bodies, 100);
        window.display();
    }
}