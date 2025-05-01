#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {
    typedef unsigned char rgb_value;

    class Color {
    private:
        unsigned char red_value;
        unsigned char green_value;
        unsigned char blue_value;

    public:
        Color();

        Color(const Color &c);

        Color(rgb_value r, rgb_value g, rgb_value b);

        rgb_value red() const;

        rgb_value &red();

        rgb_value green() const;

        rgb_value &green();

        rgb_value blue() const;

        rgb_value &blue();
    };
}

std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
