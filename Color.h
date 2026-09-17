#pragma once
#include <fstream>

class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;

    friend std::ifstream& operator>>(std::ifstream& in, Color& color);

  private:
    double r{};
    double g{};
    double b{};
};
