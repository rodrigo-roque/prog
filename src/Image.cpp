#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        width_value_ = w; // Atribui w ao valor da largura
        height_value_ = h; // Atribui h ao valor da altura
        for (int i=0; i<h;i++) { // Repete o ciclo h vezes, de modo a criar h linhas da matriz
            std::vector <Color> current_line; // Cria um vetor que será utilizado para armazenar uma linha completa
            for (int j=0; j<w; j++) { // Repete o ciclo w vezes, de modo a criar w colunas numa linha
                current_line.push_back(fill); // Adiciona o valor de "fill" à linha atual
            }
            pixels_.push_back(current_line); // Adiciona a linha atual à matriz
        }
    }

    // Destrutor
    Image::~Image() {}

    int Image::width() const {
        return width_value_; // Retorna o valor da largura
    }

    int Image::height() const {
        return height_value_; // Retorna o valor da altura
    }

    Color &Image::at(int x, int y) {
        return pixels_[y][x];  // Retorna o valor (Cor) que está no pixel da matriz localizado na linha y, na coluna x
    }

    const Color &Image::at(int x, int y) const {
        return pixels_[y][x]; // Retorna o valor (Cor) que está no pixel da matriz localizado na linha y, na coluna x
    }
}
