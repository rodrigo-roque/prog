#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {
    typedef unsigned char rgb_value; // O valor rgb passa a ser um unsigned char (está entre 0-255)

    class Color {
    private:
        rgb_value red_value; // Valor de vermelho
        rgb_value green_value; // Valor de verde
        rgb_value blue_value; // Valor de azul

    public:
        Color(); // Construtor vazio

        Color(const Color &c); // Construtor cópia

        Color(rgb_value r, rgb_value g, rgb_value b); // Construtor padrão das cores

        rgb_value red() const; // Acessor da cor vermelha (constante)

        rgb_value &red(); // Acessor da cor vermelha

        rgb_value green() const; // Acessor da cor verde (constante)

        rgb_value &green(); // Acessor da cor verde

        rgb_value blue() const; // Acessor da cor azul (constante)

        rgb_value &blue(); // Acessor da cor azul
    };
}

std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
