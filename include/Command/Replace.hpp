//
// Created by Tiago on 03/05/2025.
//

#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP


#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            // Contrutor padrão com o comando "Replace"
            Replace(Color& base_color, Color &new_color);

            // Destrutor
            ~Replace();

            // Função que implementa o comando "Replace"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;

        private:
            Color base_color_; // Cor base a mudar na imagem
            Color new_color_; // Cor nova a atualizar na imagem
        };
    }
}

#endif //PROJECT_REPLACE_HPP
