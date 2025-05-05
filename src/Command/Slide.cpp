//
// Created by franc on 05/05/2025.
//
#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <vector>

namespace prog {

    namespace command {
        Slide::Slide(int x, int y): Command("Slide"), x_offset(x), y_offset(y){}

        Slide::~Slide() {};

        Image *Slide::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            Color fill(255, 255, 255);

            Image* original = img;
            Image* result = new Image(w, h, fill);

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    int new_x = (x + x_offset) % w; //  Ex: para w=5, x=4 e x_offset = 2 -> (4 + 2) % 5 = 6 % 5 = 1
                    if (new_x < 0) new_x += w;

                    int new_y = (y + y_offset) % h;
                    if (new_y < 0) new_y += h;

                    result->at(new_x, new_y) = original->at(x, y);
                    }
                }
            delete original;
            return result;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_offset << " y:" << y_offset;
            return ss.str();
        }
    }
}