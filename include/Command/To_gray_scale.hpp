//
// Created by franc on 03/05/2025.
//

#ifndef TO_GRAY_SCALE_HPP
#define TO_GRAY_SCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Gray : public Command {
        public:
            //Contrutor padrão com o comando "to_gray_scale"
            Gray();

            //Destrutor
            ~Gray() override;

            //Função que implementa o comando "to_gray_scale"
            Image *apply(Image *img) override;
        };
    }
}

#endif //TO_GRAY_SCALE_HPP
