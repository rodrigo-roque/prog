//
// Created by Tiago on 04/05/2025.
//

#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "fill"
        Crop::Crop(int x, int y, int w, int h) : Command("crop"), x_(x), y_(y), w_(w), h_(h) {}

        //Destrutor
        Crop::~Crop() {};

        //Função que implementa o comando "fill"
        Image *Crop::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem
            //A função "min", a seguir apresentada previne que a altura e largura de recorte
            //seja tenham valores fora das dimensões da imagem
            //Será o menor valor entre a altura/largura desejada e o que resta da imagem a partir de x_/y_
            int crop_height = std::min(h_, img_height - y_); //Dimensão de recorte em y (altura)
            int crop_width = std::min(w_, img_width - x_); // Dimensão de recorte em x (largura)

            Image* cropped = new Image(crop_width,crop_height); //Nova imagem com as dimensões finais -> Imagem a usar para modificações

            for (int y = 0; y < crop_height; y++) { //Percorre os pixeis da imagem linha por linha, coluna por coluna, da nova imagem
                for (int x = 0; x < crop_width; x++) {
                    //Acede ao pixel na posição (x, y) da nova imagem e substitui pelo correspondente da imagem original
                    //A posição do pixel na imagem original é deslocada pelas coordenadas do pixel de origem do recorte (x_, y_)
                    cropped->at(x, y) = img->at(x_ + x, y_ + y);
                }
            }
            delete img; //Apagar a imagem original (argumento), para prever Memory Leaks
            return cropped; //Retornar a nova imagem "cropped", com as alterações esperadas
        }

        //Função de conversão para string
        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return ss.str();
        }
    }
}