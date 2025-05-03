//
// Created by Tiago on 03/05/2025.
//

#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Replace::Replace(Color& base, Color &to_fill) : Command("Replace"), base_(base), to_fill_(to_fill) {}

        Replace::~Replace() {};

        Image *Replace::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //percorre os pixeis da imagem linha por linha e inverte as cores de cada um
                for (int x = 0; x < w; x++) {
                    Color &c = img->at(x, y); // Acede ao pixel na posição (x, y)
                    if (c.red() == base_.red() && c.green() == base_.green() && c.blue() == base_.blue()) { //Verificar se o pixel tem os valores base (alvo a mudar se verdadeiro)
                        c.red() = to_fill_.red();
                        c.green() = to_fill_.green();
                        c.blue() = to_fill_.blue();
                    }
                }
            }
            return img;
        }
    }
}