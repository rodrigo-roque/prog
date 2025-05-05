//
// Created by Tiago on 04/05/2025.
//
//Passou nos testes, mas tem MLeaks.

#include "Command/Rotate_Left.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        R_Left::R_Left() : Command("rotate_left") {}

        R_Left::~R_Left() {}

        Image *R_Left::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            int new_w = h; // Guarda a largura da nova imagem
            int new_h = w; // Guarda a altura da nova imagem

            Image* original = img; //Criar uma imagem cópia da original, para não ter memory leaks
            Image* rotate_left = new Image(new_w, new_h);

            for (int y = 0; y < h; y++) { //percorre os pixeis da imagem coluna por coluna, linha por linha
                for (int x = 0; x < w; x++) {
                    rotate_left->at(y, new_h - 1 - x) = original->at(x, y); // Acede ao pixel na posição (x, y) da imagem rodada e altera para o valor da imagem inicial
                }
            }
            delete original; //Apagar a cópia, para não ter memory leaks
            return rotate_left;
        }
    }
}