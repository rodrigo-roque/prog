//
// Created by franc on 05/05/2025.
//

#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            // Construtor padrão com o comando "Add", ficheiro, cor neutra e posição x, y
            Add(std::string filename, Color &neutral, int x, int y);

            // Destrutor
            ~Add();

            // Função que implementa o comando "Add"
            Image *apply(Image *img) override;

            // Função que converte o comando para string
            std::string toString() const override;

        private:
            std::string filename; // Nome do ficheiro da imagem a adicionar
            Color neutral_; // Cor considerada neutra (transparente) na imagem a adicionar
            int x_, y_; // Coordenadas de destino (canto superior esquerdo) onde a imagem será adicionada

        };
    }
}
#endif //PROJECT_ADD_HPP
