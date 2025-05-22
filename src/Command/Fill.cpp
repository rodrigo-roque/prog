//
// Created by Tiago on 04/05/2025.
//

#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "fill"
        Fill::Fill(int x, int y, int w, int h, Color &fill_color) : Command("fill"), x_(x) , y_(y) , w_(w), h_(h), fill_color_(fill_color) {}

        // Destrutor
        Fill::~Fill() {};

        // Função que implementa o comando "fill"
        Image *Fill::apply(Image *img) {
             // Percorre a imagem, apenas dentro do retângulo que vai sofrer alterações
             // "modified_y" e "modified_x" são as posições dos pixeis dentro do retêngulo que sofre alerações.
             // Altura = (y_ + h_) / Largura = (x_ + w_) -> Conta = (Ponto de partida + tamanho do lado do retângulo).
            for (int modified_y = y_; modified_y < y_ + h_; modified_y++) {
                for (int modified_x = x_; modified_x < x_ + w_; modified_x++) {
                    img->at(modified_x, modified_y) = fill_color_; // Mudança da cor para a cor a preencher
                }
            }
            return img; // Retorna a imagem, já modificada
        }

        // Função de conversão para string
        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_ << " RGB_Value:" << fill_color_;
            return ss.str();
        }
    }
}
