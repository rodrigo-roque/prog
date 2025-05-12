#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        width_value = w;
        height_value = h;
        for (int i=0; i<h;i++) {
            std::vector <Color> current_line;
            for (int j=0; j<w; j++) {
                current_line.push_back(fill);
            }
            pixels.push_back(current_line);
        }
    }

    Image::~Image() { // se eventualmente usarmos memoria alocada, tem que ser mudado
    }

    int Image::width() const {
        return width_value;
    }

    int Image::height() const {
        return height_value;
    }

    Color &Image::at(int x, int y) {
        return pixels[y][x];
    }

    const Color &Image::at(int x, int y) const {
        return pixels[y][x]; //ola
    }
}
