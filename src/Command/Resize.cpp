//
// Created by Tiago on 04/05/2025.
//

#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "resize"
        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x_(x), y_(y), w_(w), h_(h) {}

        // Destrutor
        Resize::~Resize() {};

        // Função que implementa o comando "resize"
        Image *Resize::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem original
            int img_height = img->height(); // Guarda a altura da imagem original
            Image* resized = new Image(w_,h_); // Nova imagem com as dimensões finais

            for (int y = 0; y < h_; y++) {
                for (int x = 0; x < w_; x++) {
                    // Calcula a coordenada na imagem "resized", cam valor das coordenadas de loop,
                    // somando a posição de origem (x_, y_) da área inserida -> Deslocamento.
                    int pos_img_x = x + x_; // Coordenada x dentro imagem "resized"
                    int pos_img_y = y + y_; // Coordenada y dentro imagem "resized"

                    // Cópia do pixel da imagem original para a imagem "resized", verificando se os limites são respeitados
                    if (pos_img_x >= 0 && pos_img_x < img_width && pos_img_y >= 0 && pos_img_y < img_height) {
                        resized->at(x, y) = img->at(pos_img_x, pos_img_y);
                    }
                }
            }
            delete img; // Apagar a imagem original, para não ter memory leaks
            return resized; // Retorna a "resized", agora com as alterações pretendidas
        }

        // Função de conversão para string
        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return ss.str();
        }
    }
}
