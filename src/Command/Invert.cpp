//
// Created by franc on 02/05/2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "invert"
        Invert::Invert() : Command("invert") {}

        //Destrutor
        Invert::~Invert() {}
        //Função que implementa o comando "invert"
        Image *Invert::apply(Image *img) {
            int w = img->width(); //Guarda a largura da imagem
            int h = img->height(); //Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //Percorre os pixeis da imagem linha por linha, coluna por coluna, e inverte as cores de cada um
                for (int x = 0; x < w; x++) {
                    Color &c = img->at(x, y); //Acede ao pixel na posição (x, y)
                    //Atualiza os componentes de cor do objeto "c", com os valores invertidos (255 - cor)
                    c.red() = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue() = 255 - c.blue();
                }
            }
            return img; //Retorna a imagem, agora com as cores invertidas
        }
    }
}