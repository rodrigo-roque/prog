//
// Created by franc on 02/05/2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "invert"
        Invert::Invert() : Command("Invert") {}

        // Destrutor
        Invert::~Invert() {}

        // Função que implementa o comando "invert"
        Image *Invert::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < img_height; y++) { // Percorre os pixeis da imagem linha por linha, coluna por coluna, e inverte as cores de cada um
                for (int x = 0; x < img_width; x++) {
                    Color &c = img->at(x, y); // Acede ao pixel na posição (x, y)
                    // Atualiza os componentes de cor do objeto "c", com os valores invertidos (255 - cor)
                    c.red() = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue() = 255 - c.blue();
                }
            }
            return img; // Retorna a imagem, agora com as cores invertidas
        }
    }
}