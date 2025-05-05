//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_ROTATE_LEFT_HPP
#define PROJECT_ROTATE_LEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class R_Left : public Command {
        public:
            R_Left();
            ~R_Left() override;

            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_ROTATE_LEFT_HPP
