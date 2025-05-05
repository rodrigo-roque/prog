//
// Created by franc on 05/05/2025.
//

#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            Add(std::string filename, int x, int y, Color &fill);

            ~Add();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename;
            int x, y;
            Color fill;
        };
    }
}
#endif //PROJECT_ADD_HPP
