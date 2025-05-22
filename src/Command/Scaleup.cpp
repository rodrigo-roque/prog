//
// Created by Tiago on 05/05/2025.
//

#include "Command/Scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        // Contrutor padrão com o comando "Scaleup"
        Scaleup::Scaleup(int x, int y) : Command("Scaleup"), factor_x_(x), factor_y_(y){}

        // Destrutor
        Scaleup::~Scaleup() {}

        // Função que implementa o comando "Scaleup"
        Image *Scaleup::apply(Image *img) {
            int w = img->width(); // Guarda a largura da imagem
            int h = img->height(); // Guarda a altura da imagem
            int new_w = w * factor_x_; // Guarda a largura da nova imagem, proporcional ao fator de escala horizontal (factor_x_)
            int new_h = h * factor_y_; // Guarda a altura da nova imagem, proporcional ao fator de escala vertical (factor_y_)

            Image* scaledup = new Image(new_w, new_h); // Nova imagem, com tamanho novo, onde são feitas as alterações

            for (int y_original = 0; y_original < h; y_original++) { // Percorre os pixeis da imagem coluna por coluna, linha por linha
                for (int x_original = 0; x_original < w; x_original++) {
                    Color pixel_original = img->at(x_original, y_original); // Pixel da imagem a expandir
                    // Percorre os pixeis da nova imagem coluna por coluna, linha por linha,
                    // dentro dos limites de expansão de cada pixel antigo.
                    // Aplica o pixel "pixel_original" aos pixeis dentro do bloco.
                    for (int y = 0; y < factor_y_; y++) {
                        for (int x = 0; x < factor_x_; x++) {
                            // O produto das coordenadas originais com os fatores x/y garante a expansão do pixel
                            // Os valores "x" e "y" indicam o deslocamento dentro do bloco, proveniente da expansão
                            // "x_novo" e "y_novo" aplicam a escala corretamente, preservando as posições relativas de cada pixel dentro de um bloco
                            int new_x = x_original * factor_x_ + x; // Valor da coordenada x da nova imagem
                            int new_y = y_original * factor_y_ + y; // Valor da coordenada y da nova imagem
                            scaledup->at(new_x, new_y) = pixel_original; // Atribuição do pixel antigo a pixeis na imagem nova, expandindo-a
                        }
                    }
                }
            }
            delete img; // Apagar a imagem principal, para não ter memory leaks
            return scaledup; // Retornar a nova imagem "scaledup" agora modificada
        }

        // Função de conversão para string
        std::string Scaleup::toString() const {
            std::ostringstream ss;
            ss << name() << " Fator em x:" << factor_x_ << " Fator em y:" << factor_y_;
            return ss.str();
        }
    }
}