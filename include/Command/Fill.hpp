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
            // Contrutor padrão com o comando "fill"
            Fill(int x, int y, int w, int h, Color &fill_color);

            // Destrutor
            ~Fill();

            // Função que implementa o comando "fill"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;

        private:
            int x_; // Valor da coordenada x do pixel do canto superior esquerdo
            int y_; // Valor da coordenada y do pixel do canto superior esquerdo
            int w_; // Largura de limite de preenchimento
            int h_; // Altura de limite de preenchimento
            Color fill_color_; //Cor nova a alterar
        };
    }
}

#endif //PROJECT_FILL_HPP
