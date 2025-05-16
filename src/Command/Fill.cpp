//
// Created by Tiago on 04/05/2025.
//

#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "fill"
        Fill::Fill(int x, int y, int w, int h, Color &RGB_values) : Command("fill"), x_(x) , y_(y) , w_(w), h_(h), RGB_values_(RGB_values) {}

        //Destrutor
        Fill::~Fill() {};

        //Função que implementa o comando "fill"
        Image *Fill::apply(Image *img) {
        //Percorre a imagem, apenas dentro do retângulo que vai sofrer alterações
        //"dentro_y" e "dentro_x" são as posições dos pixeis dentro do retêngulo que sofre alerações
        //Altura = (y_ + h_) / Largura = (x_ + w_) -> Conta = (Ponto de partida + tamanho do lado do retângulo)
            for (int dentro_y = y_; dentro_y < y_ + h_; dentro_y++) {
                for (int dentro_x = x_; dentro_x < x_ + w_; dentro_x++) {
                    img->at(dentro_x, dentro_y) = RGB_values_; //Mudança da cor para a cor a preencher
                }
            }
            return img; //Retorna a imagem, já modificada
        }

        //Função de conversão para string
        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_ << " RGB_Value:" << RGB_values_;
            return ss.str();
        }
    }
}
