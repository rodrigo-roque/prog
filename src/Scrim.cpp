//
// Created by JBispo on 05/04/2025.
//
#include "Scrim.hpp"
#include "Logger.hpp"
#include "ScrimParser.hpp"


using std::ifstream;
using std::istream;
using std::string;
using std::vector;

using prog::Command;

namespace prog {
    Scrim::Scrim(std::vector<Command *> &commands) : commands(commands) {
    }

    Scrim::~Scrim() {
        // Deallocate each command
        for (Command *c: commands) {
            delete c;
        }
    };

    Image *Scrim::run(Image *img) {
        for (Command *c: commands) {
            *Logger::out() << "Applying command '" << c->toString() << "'\n";
            img = c->apply(img);
        }

        return img;
    }

    Image *Scrim::run() {
        return this->run(nullptr);
    }

    vector<Command *> Scrim::getCommands() const {
        return commands;
    }


    vector<Command *> Scrim::chain() const{

        //criar lista com os scrims a utilizar
        //guardar a operação final
        //tentar abrir os scrims como faz o parser, estando atentos às instruções que devemos ignorar
        //à medida que abrimos scrims adicionamos o nome à lista para ajudar na recursao
        //obter a lista de instruções provenientes dos scrims
        //adicionar instrução final

        vector<Command *> chained_commands=getCommands();
        for (auto scrim: chained_commands) {
            string command_n=scrim->toString();
            if (command_n == "end" || command_n.find("save")) return chained_commands; //ainda nao tenho a ctz do save se der erro eventualmente aicionar o save no final;
            else {
                vector <string> used_scrims;
                string command_name;
                ifstream file(command_n);
                while (file >> command_name) {

                }



            }






        }






    }

}
