//
// Created by Tiago on 04/05/2025.
//

#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Fill::Fill(int x, int y, int w, int h, Color &RGB_values) : Command("fill"), x_(x) , y_(y) , w_(w), h_(h), RGB_values_(RGB_values) {}

        Fill::~Fill() {};

        Image *Fill::apply(Image *img) {
            for (int y_c = y_; y_c < y_ + h_; y_c++) {
                for (int x_c = x_; x_c < x_ + w_; x_c++) {
                    Color &cor_atual = img->at(x_c, y_c);
                    cor_atual = RGB_values_;
                }
            }
            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_ << " RGB_Value:" << RGB_values_;
            return ss.str();
        }

    }
}
