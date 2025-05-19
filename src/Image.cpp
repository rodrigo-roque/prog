#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        width_value = w; //atribui w ao valor da largura
        height_value = h; //atribui h ao valor da altura
        for (int i=0; i<h;i++) { //repete o ciclo h vezes, de modo a criar h linhas da matriz
            std::vector <Color> current_line; //cria um vetor que será utilizado para armazenar uma linha completa
            for (int j=0; j<w; j++) { //repete o ciclo w vezes, de modo a criar w colunas numa linha
                current_line.push_back(fill); //adiciona o valor de "fill" à linha atual
            }
            pixels.push_back(current_line); //adiciona a linha atual à matriz
        }
    }

    Image::~Image() {} //destrutor

    int Image::width() const {
        return width_value; //retorna o valor da largura
    }

    int Image::height() const {
        return height_value; //retorna o valor da altura
    }

    Color &Image::at(int x, int y) {
        return pixels[y][x];  //retorna o valor (Cor) que está no pixel da matriz localizado na linha y, na coluna x
    }

    const Color &Image::at(int x, int y) const {
        return pixels[y][x]; //retorna o valor (Cor) que está no pixel da matriz localizado na linha y, na coluna x
    }
}
