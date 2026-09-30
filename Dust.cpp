#include "Dust.hpp"
#include <algorithm>

void Dust::addParticles(const Point &coords) {
    for (size_t i = 0; i < default_particle_num; i++) {
        double angle = 2 * M_PI / default_particle_num * i;
        Velocity v(default_particle_speed, angle);
        Ball newBall(coords, v, default_particle_radius, default_particle_color, false);
        particles.push_back(std::move(newBall));
    }
    return;
}

void Dust::draw(Painter &painter) const {
    if (particles.empty()) return;
    for (const auto& p : particles) {
        p.ball.draw(painter);
    }
    return;
}

void Dust::update(const size_t ticks) {
    if (particles.empty()) return;
    for (size_t i = 0; i < ticks; i++) {
        for (auto it = particles.begin(); it != particles.end(); ++it) {
            it->ball.setCenter(it->ball.getCenter() + it->ball.getVelocity().vector());
            it->ttl--;
        }
        particles.erase(
            std::remove_if(particles.begin(), particles.end(), 
                [](const Particle& p) { return p.ttl == 0; }),
            particles.end());
    }
    return;
}
