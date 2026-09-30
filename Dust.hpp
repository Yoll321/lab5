#pragma once

#include "Ball.hpp"
#include <vector>

const double default_particle_speed  = 0.5;
const double default_particle_radius = 20;
const size_t default_particle_ttl    = 1000;
const Color  default_particle_color  = { 1, 1, 0 };
const size_t default_particle_num    = 16;

class Dust {
public:
    Dust() = default;
    void addParticles(const Point& coords);
    void draw(Painter& painter) const;
    void update(const size_t ticks);
    
private:
    struct Particle {
        Ball ball;
        size_t ttl;
        Particle(const Ball& ball) :
            ball(ball), ttl(default_particle_ttl) {}
    };
    std::vector<Particle> particles;
};