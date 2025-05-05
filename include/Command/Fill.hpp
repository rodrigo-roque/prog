//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP


#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, Color &RGB_values);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x_;
            int y_;
            int w_;
            int h_;
            Color RGB_values_;
        };
    }
}

#endif //PROJECT_FILL_HPP
