#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() {
        red_value=0;
        green_value=0;
        blue_value=0;
    }

    Color::Color(const Color &other) {
        red_value=other.red_value;
        green_value=other.green_value;
        blue_value=other.blue_value;
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        red_value=red;
        green_value=green;
        blue_value=blue;
    }

    rgb_value Color::red() const {
        return red_value;
    }

    rgb_value Color::green() const {
        return green_value;
    }

    rgb_value Color::blue() const {
        return blue_value;
    }



    rgb_value &Color::red() {
        return red_value;
    }

    rgb_value &Color::green() {
        return green_value;
    }

    rgb_value &Color::blue() {
        return blue_value;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
