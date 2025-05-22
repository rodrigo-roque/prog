#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include <sstream>

namespace prog {
    namespace command {
        // Construtor com o comando chain
        Chain::Chain(const std::vector<std::string>& files): Command("Chain"), files_(files) {}

        // Destrutor
        Chain::~Chain() {}

        // Helper Function usada para verificar se um ficheiro já foi utilizado no chain evitando um loop infito
        bool already_used (const std::vector<std::string>& used_files, const std::string& file) {
                for (auto file_: used_files) { // Itera sobre o vetor dos ficheiros que já foram utilizados
                    if (file_ == file) return true; // Se o ficheiro já foi utilizado, retorna true
                }
                return false;// Se não foi utilizado retorna false
            };

        // Aplica o comando "chain" à imagem
        Image* Chain::apply(Image* img) {
            std::vector<std::string> used_files; // Vetor de ficheiros que já foram utilizados no chain para evitar loops infinitos

            for (auto file: files_) { // Itera sobre os ficheiros do chain
                if (already_used(used_files, file)) { // Verifica se este ficheiro já foi utilizado para evitar loops infinitos.
                    continue; // Se já foi utilizado, passa para o próximo.
                }
                used_files.push_back(file); // Adciona o ficheiro ao vector de ficheiros utilizados
                ScrimParser parser; // Cria um parser para o ficheiro
                Scrim* scrim = parser.parseScrim(file); // Utiliza o parser para ler o ficheiro

                std::vector<Command*> commands = scrim->getCommands(); // Obtem os comandos do scrim e armazena num vector
                for (auto command : commands) { // Itera sobre os comandos do vetor
                    std::string command_name = command->name(); // Obtem o nome do comando.
                    if (command_name == "Save" || command_name == "Blank" || command_name == "Open") {
                        continue; // Ignora os comandos de "save", "blank" e "open".
                    }
                    if (command_name == "Chain") { // Se for um comando de "chain" temos um nested chain
                        Chain* chain_command = (Chain*)command; // Converte o comando para um tipo de Chain
                        for (auto nested_file:  chain_command->files_) { // Itera sobre os ficheiros do nested chain
                            if (already_used(used_files, nested_file)) { // Verifica se este ficheiro já foi utilizado para evitar loops infinitos.
                                continue; // Se já foi utilizado, passa para o próximo.
                            }
                            used_files.push_back(nested_file); // Adciona o ficheiro ao vector de ficheiros utilizados
                            Scrim* nested_scrim = parser.parseScrim(nested_file); // Utiliza o parser para ler o ficheiro
                            if (nested_scrim) { // Verifica se o "nested_scrim" não é um "nullptr", para evitar erros de execução
                                std::vector<Command*> nested_commands = nested_scrim->getCommands(); // Obtem os comandos do scrim e armazena num vector
                                for (auto nested_command:nested_commands) { // Itera sobre os comandos do vetor.
                                    std::string nested_command_name = nested_command->name(); // Obtem o nome do comando.
                                    // Ignora os comandos de "save", "blank" e "open".
                                    //Ignora o comando "chain" para prevenir execução dentro de nested chain.
                                    if (nested_command_name == "Save" || nested_command_name == "Blank" || nested_command_name == "Open" || nested_command_name == "Chain") continue;
                                    img = nested_command->apply(img); // Aplica o comando à "img".
                                }
                                delete nested_scrim; // Deleta o scrim para evitar memory leaks
                            }
                            // Remove o último ficheiro utilizado do vector de ficheiros utilizados,
                            // pois pode voltar a ser utilizado noutro ficheiro
                            used_files.pop_back();
                        }
                    } else {
                        img = command->apply(img); // Aplica o comando à "img"
                    }
                }
                delete scrim; // Deleta o scrim para evitar memory leaks.
                // Remove o último ficheiro utilizado do vector de ficheiros utilizados,
                // pois pode voltar a ser utilizado noutro ficheiro.
                used_files.pop_back();
            }
            return img; // Retorna a imagem já modificada
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << "Chain: ";
            for (auto file: files_) ss << file << " ";
            return ss.str();
        }
    }
} 