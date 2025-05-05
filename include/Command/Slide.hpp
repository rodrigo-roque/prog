//
// Created by franc on 05/05/2025.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Slide : public Command {
        public:
            Slide(int x, int y);
            ~Slide();

            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            int x_offset;
            int y_offset;
        };
    }
}
#endif //SLIDE_HPP
