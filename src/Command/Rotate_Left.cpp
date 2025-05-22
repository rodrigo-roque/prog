//
// Created by Tiago on 04/05/2025.
//

#include "Command/Rotate_Left.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "rotate_left"
        R_Left::R_Left() : Command("Rotate_left") {}

        // Destrutor
        R_Left::~R_Left() {}

        // Função que implementa o comando "rotate_left"
        Image *R_Left::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem
            // Troca do valores de altura e largura, pois a imagem é rodada
            int new_w = img_height; // Guarda a largura da nova imagem
            int new_h = img_width; // Guarda a altura da nova imagem

            Image* rotated_left = new Image(new_w, new_h); // Nova imagem, onde são feitas as alterações pretendidas
            // Altura -> Largura e Largura -> Altura (roda 90º para a esquerda)

            for (int x = 0; x < img_height; x++) { // Percorre os pixeis da imagem original coluna por coluna, linha por linha
                for (int y = 0; y < img_width; y++) {
                    // A coluna da imagem nova será "(new_h - 1 - y)" e a linha da imagem nova será
                    // "x", pois este é a posição espelhada horizontalmente à posição vertical original.
                    rotated_left->at(x, new_h - 1 - y) = img->at(y, x); // Adaptar "img", em função do formato da nova imagem (trocar as coordenadas)
                }
            }
            delete img; // Apagar a cópia, para não ter memory leaks
            return rotated_left; // Retornar a nova imagem, rodada 90º para a esquerda
        }
    }
}