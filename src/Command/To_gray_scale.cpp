//
// Created by franc on 03/05/2025.
//
#include "Command/To_gray_scale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "to_gray_scale"
        Gray::Gray() : Command("to_gray_scale") {}

        //Destrutor
        Gray::~Gray() {}

        //Função que implementa o comando "to_gray_scale"
        Image *Gray::apply(Image *img) {
            int w = img->width(); //Guarda a largura da imagem
            int h = img->height(); //Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //Percorre os pixeis da imagem linha por linha, coluna por coluna
                for (int x = 0; x < w; x++) {
                    Color &c = img->at(x, y); //Acede ao pixel na posição (x, y)
                    int v = (c.red()+c.green()+c.blue())/3; //Cálculo da média das cores RGB de cada pixel
                    //Atualiza os componentes de cor do objeto "c", com os valores da variável "v" (cor nova)
                    c.red() = v;
                    c.green() = v;
                    c.blue() = v;
                }
            }
            return img; //Retorna a imagem, agora modificada
        }
    }
}