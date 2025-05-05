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
        Add::Add(std::string filename, Color &neutral, int x, int y) : Command("Add"), filename(filename), neutral(neutral), x(x), y(y)   {}

        Add::~Add() {};

        Image *Add::apply(Image *img) {

            // TODO:  fix rootpath
            // img = loadFromPNG("../"+filename);
            Image *nova = loadFromPNG(filename);
            int dest_w = img->width();
            int dest_h = img->height();
            int src_w = nova->width();
            int src_h = nova->height();

            for (int j = 0; j < src_h; ++j) {
                for (int i = 0; i < src_w; ++i) {
                    Color pixel = nova->at(i, j);

                    // Ignora pixeis neutros
                    if (pixel.red() == neutral.red() && pixel.green() == neutral.green() && pixel.blue() == neutral.blue())
                        continue;

                    // Calcula posição destino
                    int dest_x = x + i;
                    int dest_y = y + j;

                    // Verifica se está dentro dos limites da imagem de destino
                    if (dest_x >= 0 && dest_x < dest_w && dest_y >= 0 && dest_y < dest_h) {
                        img->at(dest_x, dest_y) = pixel;
                    }
                }
            }
            delete nova; // evita memory leak
            return img;
        }
        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}


