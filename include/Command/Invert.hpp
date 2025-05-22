//
// Created by franc on 02/05/2025.
//

#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            // Contrutor padrão com o comando "invert"
            Invert();

            // Destrutor
            ~Invert();

            // Função que implementa o comando "invert"
            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_INVERT_HPP
