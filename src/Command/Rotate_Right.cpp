//
// Created by Tiago on 04/05/2025.
//
//Passou nos testes, mas tem MLeaks.

#include "Command/Rotate_Right.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "rotate_right"
        R_Right::R_Right() : Command("rotate_right") {}

        // Destrutor
        R_Right::~R_Right() {}

        // Função que implementa o comando "rotate_right"
        Image *R_Right::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            // Troca do valores de altura e largura, pois a imagem é rodada
            int new_w = h; // Guarda a largura da nova imagem
            int new_h = w; // Guarda a altura da nova imagem

            Image* rotated_right = new Image(new_w, new_h); // Nova imagem, onde são feitas as alterações pretendidas
            // Altura -> Largura e Largura -> Altura (roda 90º para a direita)

            for (int x = 0; x < h; x++) { // Percorre os pixeis da imagem original coluna por coluna, linha por linha
                for (int y = 0; y < w; y++) {
                    // A coluna da imagem nova será "new_w - 1 - x" e a linha da imagem nova será
                    // "y", pois este é a posição espelhada horizontalmente à posição vertical original.
                    rotated_right->at(new_w - 1 - x, y) = img->at(y, x); // Adaptar "img", em função do formato da nova imagem (trocar as coordenadas)
                }
            }
            delete img; // Apagar a cópia, para não ter memory leaks
            return rotated_right; // Retornar a nova imagem, rodada 90º para a direita
        }
    }
}