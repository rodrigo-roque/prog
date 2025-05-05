//
// Created by franc on 04/05/2025.
//
#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <vector>

namespace prog {

    namespace command {
        Move::Move(int x, int y): Command("move"), x_offset(x), y_offset(y){}

        Move::~Move() {};

        Image *Move::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            Color fill(255, 255, 255);

            Image* original = img;
            Image* result = new Image(w, h, fill);

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    int new_x = x + x_offset;
                    int new_y = y + y_offset;

                    if (new_x < w && new_y < h) {
                        result->at(new_x, new_y) = original->at(x, y);
                    }
                }
            }
            delete original;
            return result;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_offset << " y:" << y_offset;
            return ss.str();
        }
    }
}