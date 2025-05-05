//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);
            ~Resize() override;

            Image *apply(Image *img) override;

        private:
            int x_, y_;
            int w_, h_;
        };
    }
}
#endif //PROJECT_RESIZE_HPP
