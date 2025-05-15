#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Chain::Chain(const std::vector<std::string>& files): Command("Chain"), files(files) {}

        Chain::~Chain() {}

        bool already_used (const std::vector<std::string>& used_files, const std::string& file) {
            // Helper function to check if a file is in the call stack
                for (auto file_:used_files) {
                    if (file_ == file) return true;
                }
                return false;
            };

        Image* Chain::apply(Image* img) {
            // Track files in the current call stack to avoid recursion
            std::vector<std::string> used_files;

            // Process each file in the chain
            for (auto file:files) {
                // Recursion check
                if (already_used(used_files, file)) {
                    continue;
                }
                used_files.push_back(file);
                ScrimParser parser;
                Scrim* scrim = parser.parseScrim(file);

                std::vector<Command*> commands = scrim->getCommands();
                for (auto command:commands) {
                    std::string command_name = command->name();
                    if (command_name == "Save" || command_name == "Blank" || command_name == "Open") {
                        continue;
                    }
                    if (command_name == "Chain") {
                        // Nested chain: create a new Chain and call apply recursively
                        Chain* chain_command = (Chain*)command;
                        // Add current call stack to nested call
                        for (auto nested_file:  chain_command->files) {
                            if (already_used(used_files, nested_file)) {
                                continue;
                            }
                            used_files.push_back(nested_file);
                            Scrim* nested_scrim = parser.parseScrim(nested_file);
                            if (nested_scrim) {
                                std::vector<Command*> nested_commands = nested_scrim->getCommands();
                                for (auto nested_command:nested_commands) {
                                    std::string nested_command_name = nested_command->name();
                                    if (nested_command_name == "Save" || nested_command_name == "Blank" || nested_command_name == "Open") continue;
                                    if (nested_command_name == "Chain") continue; // Avoid deeper nesting for simplicity
                                    img = nested_command->apply(img);
                                }
                                delete nested_scrim;
                            }
                            used_files.pop_back();
                        }
                    } else {
                        img = command->apply(img);
                    }
                }
                delete scrim;
                used_files.pop_back();
            }
            return img;
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << "Chain: ";
            for (auto file: files) ss << file << " ";
            return ss.str();
        }
    }
} 