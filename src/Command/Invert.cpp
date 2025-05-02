//
// Created by franc on 02/05/2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Invert::Invert(rgb_value inv_r, rgb_value inv_g, rgb_value inv_b){
            red_value = 255red_value;
            green_value = other.green_value;
            blue_value = other.blue_value;
        }

        Blank::~Blank() {};

        Image *Blank::apply(Image *img) {

            // Dispose of given image
            delete img;

            return new Image(w, h, fill);
        }


        std::string Blank::toString() const {
            std::ostringstream ss;
            ss << name() << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}