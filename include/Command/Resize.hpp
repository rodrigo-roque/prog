//
// Created by Tiago on 04/05/2025.
//

#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            // Contrutor padrão com o comando "resize"
            Resize(int x, int y, int w, int h);

            // Destrutor
            ~Resize();

            // Função que implementa o comando "resize"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;

        private:
            int x_, y_; // Coordenadas (x, y) do pixel inicial de corte do canto superior esquerdo
            int w_, h_; // Altura e largura de limite de corte (ajuste)
        };
    }
}
#endif //PROJECT_RESIZE_HPP
