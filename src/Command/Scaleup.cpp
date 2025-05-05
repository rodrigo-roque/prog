//
// Created by Tiago on 05/05/2025.
//

#include "Command/Scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Scaleup::Scaleup(int x, int y) : Command("scaleup"), x_(x), y_(y){}

        Scaleup::~Scaleup() {}

        Image *Scaleup::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            int new_w = w * x_; // Guarda a largura da nova imagem
            int new_h = h * y_; // Guarda a altura da nova imagem

            Image* original = img; //Criar uma imagem cópia da original, para não ter memory leaks
            Image* scaleup = new Image(new_w, new_h);

            for (int y_original = 0; y_original < h; y_original++) { //percorre os pixeis da imagem coluna por coluna, linha por linha
                for (int x_original = 0; x_original < w; x_original++) {
                    Color pixel_original = original->at(x_original, y_original); //Pixel da imagem a expandir
                    for (int y = 0; y < y_; y++) { //percorre os pixeis da nova imagem coluna por coluna, linha por linha, dentro dos limites de expansão de cada pixel antigo
                        for (int x = 0; x < x_; x++) {
                            int x_novo = x_original * x_ + x; //Valor da coordenada x da nova imagem
                            int y_novo = y_original * y_ + y; //Valor da coordenada y da nova imagem
                            scaleup->at(x_novo, y_novo) = pixel_original; //Atribuição do pixel antigo a pixeis na imagem nova, expandindo-a
                        }
                    }
                }
            }
            delete original; //Apagar a cópia, para não ter memory leaks
            return scaleup;
        }
    }
}