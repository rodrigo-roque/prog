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
            //Contrutor padrão com o comando "scaleup"
            Scaleup(int x, int y);

            //Destrutor
            ~Scaleup() override;

            //Função que implementa o comando "scaleup"
            Image *apply(Image *img) override;

            //Função de conversão para string
            std::string toString() const override;

        private:
            int fator_x_, fator_y_; //Fator de crescimento de cada pixel da imagem
        };
    }
}
#endif //PROJECT_SCALEUP_HPP
