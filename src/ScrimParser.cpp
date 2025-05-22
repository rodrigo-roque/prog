//
// Created by JBispo on 05/04/2025.
//
//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/To_gray_scale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/H_Mirror.hpp"
#include "Command/V_Mirror.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Add.hpp"


#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/Rotate_Left.hpp"
#include "Command/Rotate_Right.hpp"
#include "Command/Scaleup.hpp"
#include "Command/Chain.hpp"

#include "Logger.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {

        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "invert") {
            // Aplicação do comando "invert"
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            // Aplicação do comando "to_gray_scale"
            return new command::Gray();
        }

        if (command_name == "replace") {
            // Lê a informação do comando "replace"
            Color nova_cor;
            Color base;
            input >> base >>nova_cor;
            // Aplicação do comando "replace"
            return new command::Replace(base, nova_cor);
        }

        if (command_name == "h_mirror") {
            // Aplicação do comando "h_mirror"
            return new command::HMirror();
        }

        if (command_name == "v_mirror") {
            // Aplicação do comando "v_mirror"
            return new command::VMirror();
        }

        if (command_name == "fill") {
            // Lê a informação do comando "fill"
            int x, y, w, h;
            Color RGB_value;
            input >> x >> y >> w >> h >> RGB_value;
            // Aplicação do comando "fill"
            return new command::Fill(x, y, w, h, RGB_value);
        }

        if (command_name == "crop") {
            // Lê a informação do comando "crop"
            int x, y, w, h;
            input >> x >> y >> w >> h;
            // Aplicação do comando "crop"
            return new command::Crop(x, y, w, h);
        }

        if (command_name == "resize") {
            // Lê a informação do comando "resize"
            int x, y, w, h;
            input >> x >> y >> w >> h;
            // Aplicação do comando "resize"
            return new command::Resize(x, y, w, h);
        }

        if (command_name == "rotate_left") {
            // Aplicação do comando "rotate_left"
            return new command::R_Left();
        }

        if (command_name == "rotate_right") {
            // Aplicação do comando "rotate_right"
            return new command::R_Right();
        }

        if (command_name == "scaleup") {
            // Lê a informação do comando "scaleup"
            int x, y;
            input >> x >> y;
            // Aplicação do comando "scaleup"
            return new command::Scaleup(x, y);
        }

        if (command_name == "move") {
            // Lê a informação do comando "move"
            int x, y;
            input >> x >> y;
            // Aplicação do comando "move"
            return new command::Move(x, y);
        }

        if (command_name == "slide") {
            // Lê a informação do comando "slide"
            int x, y;
            input >> x >> y;
            // Aplicação do comando "slide"
            return new command::Slide(x, y);
        }

        if (command_name == "add") {
            // Lê a informação do comando "add"
            string filename;
            Color neutral;
            int x, y;
            input >> filename >> neutral >> x >> y;
            // Aplicação do comando "add"
            return new command::Add(filename,neutral, x, y );
        }

        if (command_name == "chain") {
            // Lê a informação do comando "chain"
            std::vector<std::string> files;
            std::string word;
                // Multi-line chain: read one file per line until "end"
            while (input >> word) {
                if (word == "end") break;
                files.push_back(word);
            }
            // Aplicação do comando "chain"
            return new command::Chain(files);
        }

        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}