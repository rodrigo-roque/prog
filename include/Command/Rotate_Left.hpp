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
            //Contrutor padrão com o comando "rotate_left"
            R_Left();

            //Destrutor
            ~R_Left() override;

            //Função que implementa o comando "rotate_left"
            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_ROTATE_LEFT_HPP
