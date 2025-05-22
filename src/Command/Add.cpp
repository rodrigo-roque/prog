//
// Created by franc on 05/05/2025.
//

#include "Command/Add.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>

namespace prog {

    namespace command {
        // Construtor padrão com o comando "Add", ficheiro, cor neutra e posição x, y
        Add::Add(std::string filename, Color &neutral, int x, int y) : Command("Add"), filename(filename), neutral(neutral), x(x), y(y)   {}

        // Destrutor
        Add::~Add() {};

        // Função que implementa o comando "Add"
        Image *Add::apply(Image *img) {
            Image *nova = loadFromPNG(filename); // Carrega a imagem a adicionar
            int dest_w = img->width(); // Guarda a largura da imagem de destino
            int dest_h = img->height(); // Guarda a altura da imagem de destino
            int src_w = nova->width(); // Guarda a largura da imagem a adicionar
            int src_h = nova->height(); // Guarda a altura da imagem a adicionar

            for (int j = 0; j < src_h; ++j) { //Percorre as linhas da imagem que queremos adicionar
                for (int i = 0; i < src_w; ++i) { //Percorre as colunas da imagem que queremos adicionar
                    Color pixel = nova->at(i, j); //Obtém o pixel da mesma

                    // Ignora pixeis neutros
                    if (pixel.red() == neutral.red() && pixel.green() == neutral.green() && pixel.blue() == neutral.blue())
                        continue;

                    // Calcula posição destino
                    int dest_x = x + i;
                    int dest_y = y + j;

                    // Verifica se está dentro dos limites da imagem de destino
                    if (dest_x >= 0 && dest_x < dest_w && dest_y >= 0 && dest_y < dest_h) {
                        img->at(dest_x, dest_y) = pixel; //Copia o pixel para a imagem de destino
                    }
                }
            }
            delete nova; // Evita memory leak
            return img; // Retorna a imagem de destino com a nova imagem adicionada
        }
        // Função que converte o comando para string
        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}


