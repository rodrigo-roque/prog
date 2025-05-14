//
// Created by rodri on 14/05/2025.
//

#include "Chain.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Chain::Chain(std::vector <Scrim> scrims) : Command("chain"), chained_scrims_(scrims){};
        Chain::~Chain() {};

    }
}
