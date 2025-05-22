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
        Replace::Replace(Color& base, Color &cor_nova) : Command("replace"), base_(base), nova_cor_(cor_nova) {}

        // Destrutor
        Replace::~Replace() {};

        // Função que implementa o comando "replace"
        Image *Replace::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < h; y++) { // Percorre os pixeis da imagem linha por linha, coluna por coluna
                for (int x = 0; x < w; x++) {
                    Color &c = img->at(x, y); // Acede ao pixel na posição (x, y)
                    // Verificar se o pixel tem os valores base (alvo a mudar se verdadeiro)
                    if (c.red() == base_.red() && c.green() == base_.green() && c.blue() == base_.blue()) {
                        // Atualiza os componentes de cor do objeto "c", com os valores da cor nova "nova_cor"
                        c.red() = nova_cor_.red();
                        c.green() = nova_cor_.green();
                        c.blue() = nova_cor_.blue();
                    }
                }
            }
            return img; // Retorna a imagem, agora modificada
        }

        // Função de conversão para string
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " base:" << base_ << " cor nova:" << nova_cor_;
            return ss.str();
        }
    }
}