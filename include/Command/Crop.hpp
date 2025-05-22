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
            // Contrutor padrão com o comando "fill"
            Crop(int x, int y, int w, int h);

            // Destrutor
            ~Crop() override;

            // Função que implementa o comando "fill"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;

        private:
          int x_, y_; // Coordenadas (x, y) do pixel inicial de corte do canto superior esquerdo
          int w_, h_; // Altura e largura de limite de corte
        };
    }
}
#endif //PROJECT_CROP_HPP
