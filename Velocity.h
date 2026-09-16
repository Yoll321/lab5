#pragma once
#include "Point.h"
#include <cmath>

class Velocity {
  public:
    inline Velocity() = default;

    // Задание вектора скорости при помощи длины вектора и угла его наклона
    inline Velocity(double abs, double angle) {
        // Вычисляестя единичный вектор
        const double x = std::cos(angle);
        const double y = std::sin(angle);
        // Единичный вектор домножается на длину
        vec = Point{x, y} * abs;
    }

    inline Velocity(const Point& vector) {
        setVector(vector);
    }

    inline void setVector(const Point& vector) {
        vec = vector;
    }

    inline Point vector() const {
        return vec;
    }

  private:
    Point vec;
};
