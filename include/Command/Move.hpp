//
// Created by franc on 04/05/2025.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Move : public Command {
        public:
            Move(int x, int y);
            ~Move();
            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            int x_offset;
            int y_offset;
        };
    }
}
#endif //MOVE_HPP
