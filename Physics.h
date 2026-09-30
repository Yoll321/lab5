#pragma once
#include "Ball.hpp"
#include "Dust.hpp"
#include <vector>

class Physics {
  public:
    Physics(double timePerTick = 0.001);
    void setWorldBox(const Point& topLeft, const Point& bottomRight);
    void update(std::vector<Ball>& balls, size_t ticks, Dust& dustHandler) const;

  private:
    void collideBalls(std::vector<Ball>& balls, Dust& dustHandler) const;
    void collideWithBox(std::vector<Ball>& balls) const;
    void move(std::vector<Ball>& balls) const;
    void processCollision(Ball& a, Ball& b,
                          double distanceBetweenCenters2,
                          Dust& dustHandler) const;

  private:
    Point topLeft;
    Point bottomRight;
    double timePerTick;
};
