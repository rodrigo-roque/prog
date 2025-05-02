#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        width_value=w;
        height_value=h;
        pixels = std::vector<Color>(w * h, fill);
    }

    Image::~Image() {
    }

    int Image::width() const {
        return width_value;
    }

    int Image::height() const {
        return height_value;
    }

// dont understand what to do
    Color &Image::at(int x, int y) {
        return pixels[y * width_value + x];
    }

    const Color &Image::at(int x, int y) const {
        return pixels[y * width_value + x];
    }
}
