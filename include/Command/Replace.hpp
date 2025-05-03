//
// Created by Tiago on 03/05/2025.
//

#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP


#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            Replace(Color& base, Color &to_fill);

            ~Replace();

            Image *apply(Image *img) override;

        private:
            Color base_;
            Color to_fill_;
        };
    }
}

#endif //PROJECT_REPLACE_HPP
