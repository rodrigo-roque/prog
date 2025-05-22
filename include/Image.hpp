#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
    class Image {
    private:
        int width_value; // Largura da imagem (nº de pixeis na horizontal)
        int height_value; // Altura da imagem (nº de pixeis na vertical)
        std::vector <std::vector<Color>> pixels; // Matriz de pixeis
    
	public:
        // Construtor padrão da imagem
        Image(int w, int h, const Color &fill = {255, 255, 255});

        // Destrutor
        ~Image();

        // Acessor da largura
        int width() const;

        // Acessor da altura
        int height() const;

        // Acessor da cor num determinado pixel
        Color &at(int x, int y);

        // Acessor da cor num determinado pixel (cconstante)
        const Color &at(int x, int y) const;
    };
}
#endif
