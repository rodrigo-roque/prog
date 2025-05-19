#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {
    typedef unsigned char rgb_value; //o valor rgb passa a ser um unsigned char (está entre 0-255)

    class Color {
    private:
        rgb_value red_value; //valor de vermelho
        rgb_value green_value; //valor de verde
        rgb_value blue_value; //valor de azul

    public:
        Color(); //construtor vazio

        Color(const Color &c); //construtor cópia

        Color(rgb_value r, rgb_value g, rgb_value b); //construtor padrão das cores

        rgb_value red() const; //acessor da cor vermelha (constante)

        rgb_value &red(); //acessor da cor vermelha

        rgb_value green() const; //acessor da cor verde (constante)

        rgb_value &green(); //acessor da cor verde

        rgb_value blue() const; //acessor da cor azul (constante)

        rgb_value &blue(); //acessor da cor azul
    };
}

std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
