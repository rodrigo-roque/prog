#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        width_value=w;
        height_value=h;
        color_value=fill;
    }

    Image::~Image() {
    }

    int Image::width() const {
        return width_value;
    }

    int Image::height() const {
        return height_value;
    }


    Color &Image::at(int x, int y) {
		return color_value;
    }

    const Color &Image::at(int x, int y) const {
        return color_value;
    }
}
