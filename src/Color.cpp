#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() { //construtor vazio (atribui 0 ao valor de vermelho, verde e azul)
        this->red_value=0;
        this->green_value=0;
        this->blue_value=0;
    }

    Color::Color(const Color &other) { //construtor cópia (atribui os mesmos valores da Cor que quer copiar ao vermelho, verde e azul)
        red_value=other.red_value;
        green_value=other.green_value;
        blue_value=other.blue_value;
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) { //construtor padrão
        red_value=red; //atribui o valor "red", ao valor vermelho
        green_value=green; //atribui o valor "green", ao valor verde
        blue_value=blue; //atribui o valor "blue" ao valor azul
    }

    rgb_value Color::red() const {
        return red_value; //retorna o valor de vermelho
    }

    rgb_value Color::green() const {
        return green_value; //retorna o valor de verde
    }

    rgb_value Color::blue() const {
        return blue_value; //retorna o valor de azul
    }



    rgb_value &Color::red() {
        return red_value; //retorna o valor de vermelho
    }

    rgb_value &Color::green() {
        return green_value; //retorna o valor de verde
    }

    rgb_value &Color::blue() {
        return blue_value; //retorna o valor de azul
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
