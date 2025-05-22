//
// Created by Tiago on 03/05/2025.
//

#include "Command/V_Mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "v_mirror"
        VMirror::VMirror() : Command("v_mirror") {}

        // Destrutor
        VMirror::~VMirror() {}

        // Função que implementa o comando "v_mirror"
        Image *VMirror::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            // Apenas percorre metada da altura da imagem,
            // pois troca os pixeis de cima com os de baixo, e vice-versa
            for (int y = 0; y < h/2; y++) {
                for (int x = 0; x < w; x++) { // Percorre os pixeis da imagem linha por linha
                    Color &up = img->at(x, y); // Acede ao pixel na posição (x, y)
                    Color &down = img->at(x, h-1-y); // Acede ao pixel na posição (x, height()-1-y) -> SIMÉTRICO VERTICAL
                    // Troca os valores de "up" e "down", usando uma variável temporária "temp"
                    Color temp = up;
                    up = down;
                    down = temp;
                }
            }
            return img; // Retorna a imagem, agora invertida verticalmente
        }
    }
}