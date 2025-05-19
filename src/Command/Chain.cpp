#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Chain::Chain(const std::vector<std::string>& files): Command("Chain"), files(files) {} //construtor com o comando chain

        Chain::~Chain() {} //destrutor

        bool already_used (const std::vector<std::string>& used_files, const std::string& file) { //helper function usada para verificar se um ficheiro já foi utilizado no chain evitando um loop infito
                for (auto file_:used_files) { //itera sobre o vetor dos ficheiros que já foram utilizados
                    if (file_ == file) return true; //se o ficheiro já foi utilizado retorna true
                }
                return false;//se nao foi utilizado retorna false
            };

        Image* Chain::apply(Image* img) { //aplica o comando chain à imagem
            std::vector<std::string> used_files; //vetor de ficheiros que já foram utilizados no chain para evitar loops infinitos

            for (auto file:files) { //itera sobre os ficheiros do chain
                if (already_used(used_files, file)) { //verifica se este ficheiro já foi utilizado para evitar loops infinitos
                    continue; //se já foi urilizado passa para o próximo
                }
                used_files.push_back(file); //adciona o ficheiro ao vector de ficheiros utilizados
                ScrimParser parser; //cria um parser para o ficheiro
                Scrim* scrim = parser.parseScrim(file); //utiliza o parser para ler o ficheiro

                std::vector<Command*> commands = scrim->getCommands(); //obtem os comandos do scrim e armazena num vector
                for (auto command:commands) { //itera sobre os comandos do vetor
                    std::string command_name = command->name(); //obtem o nome do comando
                    if (command_name == "Save" || command_name == "Blank" || command_name == "Open") {
                        continue; //ignora os comandos de "save", "blank" e "open"
                    }
                    if (command_name == "Chain") { //se for um comando de "chain" temos um nested chain
                        Chain* chain_command = (Chain*)command; //converte o comando para um tipo de Chain
                        for (auto nested_file:  chain_command->files) { //itera sobre os ficheiros do nested chain
                            if (already_used(used_files, nested_file)) { //verifica se este ficheiro já foi utilizado para evitar loops infinitos
                                continue; //se já foi urilizado passa para o próximo
                            }
                            used_files.push_back(nested_file); //adciona o ficheiro ao vector de ficheiros utilizados
                            Scrim* nested_scrim = parser.parseScrim(nested_file); //utiliza o parser para ler o ficheiro
                            if (nested_scrim) { //verifica se o nesets_scrim não é um nullptr, para evitar erros de execução
                                std::vector<Command*> nested_commands = nested_scrim->getCommands(); //obtem os comandos do scrim e armazena num vector
                                for (auto nested_command:nested_commands) { //itera sobre os comandos do vetor
                                    std::string nested_command_name = nested_command->name(); //obtem o nome do comando
                                    //ignora os comandos de "save", "blank" e "open", e ignora o comando "chain" para prevenir execução dentro de nested chain
                                    if (nested_command_name == "Save" || nested_command_name == "Blank" || nested_command_name == "Open" || nested_command_name == "Chain") continue;
                                    img = nested_command->apply(img); //aplica o comando ao img
                                }
                                delete nested_scrim; //deleta o scrim para evitar memory leaks
                            }
                            used_files.pop_back(); //remove o último ficheiro utilizado do vector de ficheiros utilizados, pois pode voltar a ser utilizado noutro ficheiro
                        }
                    } else {
                        img = command->apply(img); //aplica o comando ao img
                    }
                }
                delete scrim; //deleta o scrim para evitar memory leaks
                used_files.pop_back(); //remove o último ficheiro utilizado do vector de ficheiros utilizados, pois pode voltar a ser utilizado noutro ficheiro
            }
            return img; //retorna a imagem já modificada
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << "Chain: ";
            for (auto file: files) ss << file << " ";
            return ss.str();
        }
    }
} 