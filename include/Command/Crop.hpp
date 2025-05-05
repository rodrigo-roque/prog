//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);
            ~Crop() override;

            Image *apply(Image *img) override;

        private:
          int x_, y_;
          int w_, h_;
        };
    }
}
#endif //PROJECT_CROP_HPP
