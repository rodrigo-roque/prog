//
// Created by franc on 04/05/2025.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Move : public Command {
        public:
            //Construtor padrão com o comando "move" e deslocamentos x e y
            Move(int x, int y);

            //Destrutor
            ~Move();

            //Função que implementa o comando "move"
            Image* apply(Image* img) override;

            //Função que converte o comando para string
            std::string toString() const override;

        private:
            int x_offset;//Número de pixeis a mover para a direita (horizontalmente)
            int y_offset;//Número de pixeis a mover para baixo (verticalmente)
        };
    }
}
#endif //MOVE_HPP
