//
// Created by franc on 03/05/2025.
//
#include "Command/To_gray_scale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Gray::Gray() : Command("to_gray_scale") {}

        Gray::~Gray() {}

        Image *Gray::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //percorre os pixeis da imagem linha por linha e inverte as cores de cada um
                for (int x = 0; x < w; x++) {
                    Color &c = img->at(x, y); // Acede ao pixel na posição (x, y)
                    int v = (c.red()+c.green()+c.blue())/3;
                    c.red() = v;
                    c.green() = v;
                    c.blue() = v;
                }
            }
            return img;
        }
    }
}