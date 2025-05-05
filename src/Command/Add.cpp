//
// Created by franc on 05/05/2025.
//
#include "Command/Add.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>

namespace prog {

    namespace command {
        Add::Add(std::string filename, int x, int y, Color &fill) : Command("Add"), filename(filename), x(x), y(y), fill(fill)  {}

        Add::~Add() {};

        Image *Add::apply(Image *img) {

            // TODO:  fix rootpath
            // img = loadFromPNG("../"+filename);
            img = loadFromPNG(filename);

            if (!img) {
                *Logger::err() << "Could not open file " << filename << "\n";
                std::exit(1);
            }

        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }
    }
}

