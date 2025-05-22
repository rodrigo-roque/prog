#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {
        class Chain : public Command {
        public:
            // Contrutor padrão com o comando "chain"
            Chain(const std::vector<std::string>& files);

            // Destrutor
            ~Chain();

            // Função que implementa o comando "chain"
            Image *apply(Image *img) override;

            // Função de conversão para string
            std::string toString() const override;


        private:
            std::vector<std::string> files_; // Lista de ficheiros a serem processados
        };
    }
}

#endif //PROJECT_CHAIN_HPP 