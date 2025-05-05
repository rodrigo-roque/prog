//
// Created by Tiago on 04/05/2025.
//
//Passou nos testes, mas tem MLeaks.

#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Crop::Crop(int x, int y, int w, int h) : Command("crop"), x_(x), y_(y), w_(w), h_(h) {}

        Crop::~Crop() {};

        Image *Crop::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem
            int crop_height = std::min(h_, img_height - y_); //Dimensão de recorte em y
            int crop_width = std::min(w_, img_width - x_); // Dimensão de recorte em x

            Image* original = img;
            Image* cropped = new Image(crop_width,crop_height); //Nova imagem com as dimensões finais

            for (int y = 0; y < crop_height; y++) { //percorre os pixeis da imagem linha por linha e coluna por coluna da nova imagem
                for (int x = 0; x < crop_width; x++) {
                    // Acede ao pixel na posição (x, y) da nova imagem e substitui pelo correspondente da imagem original
                    cropped->at(x, y) = original->at(x_ + x, y_ + y);
                }
            }
            delete original;
            return cropped;
        }
    }
}