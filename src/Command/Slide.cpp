//
// Created by franc on 05/05/2025.
//
#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <vector>

namespace prog {

    namespace command {
        // Construtor padrão com o comando "slide" e os deslocamentos x e y
        Slide::Slide(int x, int y): Command("Slide"), x_offset_(x), y_offset_(y){}

        // Destrutor
        Slide::~Slide() {};

        // Função que implementa o comando "slide"
        Image *Slide::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem

            Color fill(255, 255, 255); // Cria uma cor branca para o fundo

            Image* original = img; // Guarda a imagem original (pointer)
            Image* result = new Image(img_width, img_height, fill); // Cria uma nova imagem com fundo branco

            for (int y = 0; y < img_height; y++) { //Percorre os pixeis da imagem linha por linha, coluna por coluna
                for (int x = 0; x < img_width; x++) {
                    // Calcula a nova posição x após o deslocamento circular:
                    // Ex: para w=5, x=4 e x_offset = 2 -> (4 + 2) % 5 = 6 % 5 = 1
                    int new_x = (x + x_offset_) % img_width;
                    if (new_x < 0) new_x += img_width; // Garante que o índice é positivo

                    // Calcula a nova posição y após o deslocamento circular, pela mesma fórmula usada para "new_x".
                    int new_y = (y + y_offset_) % img_height;
                    if (new_y < 0) new_y += img_height; // Garante que o índice é positivo

                    result->at(new_x, new_y) = original->at(x, y); // Copia o pixel para a nova posição
                }
            }
            delete original; // Liberta a memória da imagem original
            return result; // Retorna a nova imagem com os pixeis deslizados
        }

        // Função que converte o comando para string
        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_offset_ << " y:" << y_offset_;
            return ss.str();
        }
    }
}