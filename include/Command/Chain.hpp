//
// Created by rodri on 15/05/2025.
//

#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <string>
#include "Scrim.hpp"

namespace prog {
    namespace command {
        class Chain : public Command {
        public:
            Chain(std::vector <Scrim> scrims);

            ~Chain();

        private:
            std::vector <Scrim> chained_scrims_;

        };
    }
}
#endif //CHAIN_HPP
