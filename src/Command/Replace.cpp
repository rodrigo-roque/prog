//
// Created by Tiago on 03/05/2025.
//

#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        // Contrutor padrão com o comando "replace"
        Replace::Replace(Color& base_color, Color &new_color) : Command("Replace"), base_color_(base_color), new_color_(new_color) {}

        // Destrutor
        Replace::~Replace() {};

        // Função que implementa o comando "replace"
        Image *Replace::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < img_height; y++) { // Percorre os pixeis da imagem linha por linha, coluna por coluna
                for (int x = 0; x < img_width; x++) {
                    Color &c = img->at(x, y); // Acede ao pixel na posição (x, y)
                    // Verificar se o pixel tem os valores base (alvo a mudar se verdadeiro)
                    if (c.red() == base_color_.red() && c.green() == base_color_.green() && c.blue() == base_color_.blue()) {
                        // Atualiza os componentes de cor do objeto "c", com os valores da cor nova "nova_cor"
                        c.red() = new_color_.red();
                        c.green() = new_color_.green();
                        c.blue() = new_color_.blue();
                    }
                }
            }
            return img; // Retorna a imagem, agora modificada
        }

        // Função de conversão para string
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " base_color:" << base_color_ << " new_color:" << new_color_;
            return ss.str();
        }
    }
}