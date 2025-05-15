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

                std::vector<Command*> cmds = scrim->getCommands();
                for (size_t j = 0; j < cmds.size(); ++j) {
                    Command* cmd = cmds[j];
                    std::string n = cmd->name();
                    if (n == "Save" || n == "Blank" || n == "Open") {
                        continue;
                    }
                    if (n == "Chain") {
                        // Nested chain: create a new Chain and call apply recursively
                        Chain* chain_cmd = (Chain*)cmd;
                        // Add current call stack to nested call
                        for (size_t k = 0; k < chain_cmd->files.size(); ++k) {
                            std::string nested_file = chain_cmd->files[k];
                            if (already_used(used_files, nested_file)) {
                                continue;
                            }
                            used_files.push_back(nested_file);
                            Scrim* nested_scrim = parser.parseScrim(nested_file);
                            if (nested_scrim) {
                                std::vector<Command*> nested_cmds = nested_scrim->getCommands();
                                for (size_t m = 0; m < nested_cmds.size(); ++m) {
                                    Command* nested_cmd = nested_cmds[m];
                                    std::string nn = nested_cmd->name();
                                    if (nn == "Save" || nn == "Blank" || nn == "Open") continue;
                                    if (nn == "Chain") continue; // Avoid deeper nesting for simplicity
                                    img = nested_cmd->apply(img);
                                }
                                delete nested_scrim;
                            }
                            used_files.pop_back();
                        }
                    } else {
                        img = cmd->apply(img);
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