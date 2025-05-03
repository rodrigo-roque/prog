//
// Created by Utilizador on 03/05/2025.
//
#include "Command/H_Mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        HMirror::HMirror() : Command("h_mirror") {}

        HMirror::~HMirror() {}

        Image *HMirror::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //Percorre os pixeis da imagem linha por linha e inverte as cores de cada um
                for (int x = 0; x < w/2; x++) {
                    Color &left = img->at(x, y); // Acede ao pixel na posição (x, y)
                    Color &right = img->at(w-1-x, y); // Acede ao pixel na posição (width()-1-x, y) -> OPOSTO HORIZONTAL
                    Color temp = left; //Variável temporária para guardar "left"
                    left = right;
                    right = temp;
                }
            }
            return img;
        }
    }
}