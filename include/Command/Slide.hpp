//
// Created by franc on 05/05/2025.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Slide : public Command {
        public:
            // Construtor padrão com o comando "slide" e deslocamentos x e y
            Slide(int x, int y);

            // Destrutor
            ~Slide();

            // Função que implementa o comando "slide"
            Image* apply(Image* img) override;

            // Função que converte o comando para string
            std::string toString() const override;

        private:
            int x_offset; // Número de pixeis a deslizar circularmente para a direita (horizontalmente)
            int y_offset; // Número de pixeis a deslizar circularmente para baixo (verticalmente)
        };
    }
}
#endif //SLIDE_HPP
