#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    // Construtor vazio (atribui 0 ao valor de vermelho, verde e azul)
    Color::Color() {
        this->red_value_=0;
        this->green_value_=0;
        this->blue_value_=0;
    }
    // Construtor cópia (atribui os mesmos valores da Cor que quer copiar ao vermelho, verde e azul)
    Color::Color(const Color &other) {
        red_value_=other.red_value_;
        green_value_=other.green_value_;
        blue_value_=other.blue_value_;
    }

    // Construtor padrão
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        red_value_=red; // Atribui o valor "red", ao valor vermelho
        green_value_=green; // Atribui o valor "green", ao valor verde
        blue_value_=blue; // Atribui o valor "blue" ao valor azul
    }

    rgb_value Color::red() const {
        return red_value_; // Retorna o valor de vermelho
    }

    rgb_value Color::green() const {
        return green_value_; // Retorna o valor de verde
    }

    rgb_value Color::blue() const {
        return blue_value_; // Retorna  o valor de azul
    }



    rgb_value &Color::red() {
        return red_value_; // Retorna  o valor de vermelho
    }

    rgb_value &Color::green() {
        return green_value_; // Retorna  o valor de verde
    }

    rgb_value &Color::blue() {
        return blue_value_; // Retorna  o valor de azul
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
