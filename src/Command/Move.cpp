//
// Created by franc on 04/05/2025.
//
#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <vector>

namespace prog {

    namespace command {
        // Construtor padrão com o comando "Move" e os deslocamentos x e y
        Move::Move(int x, int y): Command("Move"), x_offset_(x), y_offset_(y){}

        // Destrutor
        Move::~Move() {};

        // Função que implementa o comando "Move"
        Image *Move::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem
            int img_height = img->height(); // Guarda a altura da imagem

            Color fill(255, 255, 255); // Cria uma cor branca para o fundo

            Image* original = img; // Guarda a imagem original (pointer)
            Image* result = new Image(img_width, img_height, fill); // Cria uma nova imagem com fundo branco

            for (int y = 0; y < img_height; y++) { // Percorre os pixeis da imagem linha por linha, coluna por coluna
                for (int x = 0; x < img_width; x++) {
                    int new_x = x + x_offset_; // Calcula a nova posição x após o deslocamento
                    int new_y = y + y_offset_; // Calcula a nova posição y após o deslocamento

                    if (new_x < img_width && new_y < img_height) { // Verifica se a nova posição está dentro dos limites da imagem
                        result->at(new_x, new_y) = original->at(x, y); // Copia o pixel para a nova posição
                    }
                }
            }
            delete original; // Liberta a memória da imagem original
            return result; // Retorna a nova imagem com os pixeis deslocados
        }

        // Função que converte o comando para string
        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_offset_ << " y:" << y_offset_;
            return ss.str();
        }
    }
}