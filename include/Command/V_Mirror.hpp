//
// Created by Tiago on 03/05/2025.
//

#ifndef PROJECT_V_MIRROR_HPP
#define PROJECT_V_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class VMirror : public Command {
        public:
            //Contrutor padrão com o comando "v_mirror"
            VMirror();

            //Destrutor
            ~VMirror() override;

            //Função que implementa o comando "v_mirror"
            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_V_MIRROR_HPP
