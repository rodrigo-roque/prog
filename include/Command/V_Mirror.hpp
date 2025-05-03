//
// Created by Tiago on 03/05/2025.
//

#ifndef PROJECT_V_MIRROR_HPP
#define PROJECT_V_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class VMirror : public Command {
        public:
            VMirror();
            ~VMirror() override;

            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_V_MIRROR_HPP
