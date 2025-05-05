//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_ROTATE_RIGHT_HPP
#define PROJECT_ROTATE_RIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class R_Right : public Command {
        public:
            R_Right();
            ~R_Right() override;

            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_ROTATE_RIGHT_HPP
