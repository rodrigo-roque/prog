//
// Created by Tiago on 05/05/2025.
//

#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Scaleup : public Command {
        public:
            Scaleup(int x, int y);
            ~Scaleup() override;

            Image *apply(Image *img) override;

        private:
            int x_, y_;
        };
    }
}
#endif //PROJECT_SCALEUP_HPP
