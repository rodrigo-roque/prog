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
            // Contrutor padrão com o comando "replace"
            Replace(Color& base, Color &to_fill);

            // Destrutor
            ~Replace();

            // Função que implementa o comando "replace"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;

        private:
            Color base_; // Cor base a mudar na imagem
            Color nova_cor_; // Cor nova a atualizar na imagem
        };
    }
}

#endif //PROJECT_REPLACE_HPP
