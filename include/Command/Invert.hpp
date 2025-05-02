//
// Created by franc on 02/05/2025.
//

#ifndef INVERT_HPP
#define INVERT_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert(rgb_value inv_r, rgb_value inv_g, rgb_value inv_b);

            ~Invert();

        private:
            rgb_value inv_r, inv_g, inv_b;
        };
    }
}

#endif //INVERT_HPP
