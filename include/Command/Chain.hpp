#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {
        class Chain : public Command {
        public:
            Chain(const std::vector<std::string>& files);
            ~Chain();
            Image *apply(Image *img) override;
            std::string toString() const override;
        private:
            std::vector<std::string> files;
        };
    }
}

#endif //PROJECT_CHAIN_HPP 