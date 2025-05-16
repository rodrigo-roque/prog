//
// Created by Tiago on 04/05/2025.
//

#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        //Contrutor padrão com o comando "resize"
        Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

        //Destrutor
        Resize::~Resize() {};

        //Função que implementa o comando "resize"
        Image *Resize::apply(Image *img) {
            int img_width = img->width(); // Guarda a largura da imagem original
            int img_height = img->height(); // Guarda a altura da imagem original
            Image* resized = new Image(w_,h_); //Nova imagem com as dimensões finais
            Color fill = Color(255, 255, 255); //Cor default para preencher a nova imagem "resize"

            //Aplicar a cor default a todos os pixeis da nova imagem "resize"
            for (int y_novo = 0; y_novo < h_; y_novo++) {
                for (int x_novo = 0; x_novo < w_; x_novo++) {
                    resized->at(x_novo, y_novo) = fill;
                }
            }

            //Calcular a aéra de "Overlap" entre as duas imagens
            //OVERLAP -> Pixeis que coincidem na sobreposição da imagem nova "resized", por cima da imagem original
            //Interseção entre as duas imagens
            int x_start = std::max(x_, 0); //Coordenada x no pixel inicial (canto superior esquerdo)
            int y_start = std::max(y_, 0); //Coordenada y no pixel inicial (canto superior esquerdo)
            int x_end = std::min(x_ + w_, img_width); //Coordenada x no pixel final (canto inferior direito)
            int y_end = std::min(y_ + h_, img_height); //Coordenada y no pixel final (canto inferior direito)

            //Como os limites já estão definidos, devemos copiar os pixeis que dão "Overlap"
            for (int y_original = y_start; y_original < y_end; y_original++) {
                for (int x_original = x_start; x_original < x_end; x_original++) {
                    // Calcula a coordenada na imagem "resized",
                    // subtraindo a posição de origem (x_, y_) da área inserida -> Deslocamento
                    int pos_resize_x = x_original - x_; //Coordenada x dentro imagem "resize"
                    int pos_resize_y = y_original - y_; //Coordenada y dentro imagem "resize"
                    //Cópia do pixel da imagem original para a imagem "resized"
                    resized->at(pos_resize_x, pos_resize_y) = img->at(x_original, y_original);
                }
            }
            delete img; //Apagar a imagem original, para não ter memory leaks
            return resized; //Retorna a "resized", agora com as alterações pretendidas
        }

        //Função de conversão para string
        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return ss.str();
        }
    }
}
