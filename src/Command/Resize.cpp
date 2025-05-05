//
// Created by Tiago on 04/05/2025.
//

#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

        Resize::~Resize() {};

        Image *Resize::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem original
            int img_height = img->height(); // Guarda a altura da imagem original
            Image* original = img; //Guardar a imagem inicial com pointer
            Image* resize = new Image(w_,h_); //Nova imagem com as dimensões finais
            Color fill = Color(255, 255, 255); //Cor default para preencher a nova imagem "resize"

            //Aplicar a cor default a todos os pixeis da nova imagem "resize"
            for (int y_novo = 0; y_novo < h_; y_novo++) {
                for (int x_novo = 0; x_novo < w_; x_novo++) {
                    resize->at(x_novo, y_novo) = fill;
                }
            }

            //Calcular a aéra de "Overlap" entre as duas imagens
            int x_start = std::max(x_, 0);
            int y_start = std::max(y_, 0);
            int x_end = std::min(x_ + w_, img_width);
            int y_end = std::min(y_ + h_, img_height);

            //Como os limites já estão definidos, devemos copiar os pixeis que dão "Overlap"
            for (int y_original = y_start; y_original < y_end; y_original++) {
                for (int x_original = x_start; x_original < x_end; x_original++) {
                    int pos_resize_x = x_original - x_; //Coordenada x da nova imagem "resize", a partir das coordenadas da imagem inicial
                    int pos_resize_y = y_original - y_; //Coordenada x da nova imagem "resize", a partir das coordenadas da imagem inicial

                    //Confirmação de que os valores estão dentro dos parâmetros
                    if (pos_resize_x >= 0 && pos_resize_x < w_ && pos_resize_y >= 0 && pos_resize_y < h_) {
                        resize->at(pos_resize_x, pos_resize_y) = original->at(x_original, y_original);
                    }
                }
            }
            delete original; //Apagar a imagem inicial, para não ter memory leaks
            return resize;
        }
    }
}
