//
// Created by Utilizador on 03/05/2025.
//

#ifndef PROJECT_H_MIRROR_HPP
#define PROJECT_H_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class HMirror : public Command {
        public:
            HMirror();
            ~HMirror() override;

            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_H_MIRROR_HPP
