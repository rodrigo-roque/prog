//
// Created by Tiago on 03/05/2025.
//
#include "Command/H_Mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "h_mirror"
        HMirror::HMirror() : Command("h_mirror") {}

        //Destrutor
        HMirror::~HMirror() {}

        //Função que implementa o comando "h_mirror"
        Image *HMirror::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            for (int y = 0; y < h; y++) { //Percorre os pixeis da imagem linha por linha
                //Apenas percorre metada da largura da imagem,
                //pois troca os pixeis da esquerda com os da direita, e vice-versa
                for (int x = 0; x < w/2; x++) {
                    Color &left = img->at(x, y); // Acede ao pixel na posição (x, y)
                    Color &right = img->at(w-1-x, y); // Acede ao pixel na posição (width()-1-x, y) -> SIMÉTRICO HORIZONTAL
                    //Troca os valores de "left" e "right", usando uma variável temporária "temp"
                    Color temp = left;
                    left = right;
                    right = temp;
                }
            }
            return img; //Retorna a imagem, agora invertida horizontalmente
        }
    }
}