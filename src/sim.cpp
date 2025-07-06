#include "sim.h"


std::vector<double> Sim::getDis(std::vector<double> pos1, std::vector<double> pos2) {
    return {pos2[X] - pos1[X], pos2[Y] - pos1[Y]};
}

std::vector<double> Sim::getForce(std::vector<double> dis, double mass1, double mass2) {
    double distanceSquared = dis[X]*dis[X] + dis[Y]*dis[Y];
    double magnitude = G * (mass1 * mass2) / distanceSquared;

    double distance = std::sqrt(distanceSquared);
    return { magnitude * dis[X]/distance, magnitude * dis[Y]/distance };
}

void Sim::update(double deltaTime) {
    for (int i = 0; i < bodies.size(); ++i) {
        for (int j = i + 1; j < bodies.size(); ++j) {

            std::vector<double> dis = getDis(bodies[i].pos, bodies[j].pos);
            std::vector<double> force = getForce(dis, bodies[i].mass, bodies[j].mass);

            std::vector<double> acc1 = { force[X] / bodies[i].mass, force[Y] / bodies[i].mass };
            std::vector<double> acc2 = { -force[X] / bodies[j].mass, -force[Y] / bodies[j].mass };

            bodies[i].vel[X] += acc1[X] * deltaTime;
            bodies[i].vel[Y] += acc1[Y] * deltaTime;
            bodies[j].vel[X] += acc2[X] * deltaTime;
            bodies[j].vel[Y] += acc2[Y] * deltaTime;
        }
    }

    for (auto& b : bodies) {
        b.pos[X] += b.vel[X] * deltaTime;
        b.pos[Y] += b.vel[Y] * deltaTime;
    }
}