#include "Shape.h"
#include <string>

char Shape::colourToChar(Colour c) {
    switch (c) {
        case Colour::GREEN:
            return 'G';
        case Colour::RED:
            return 'R';
        case Colour::BLUE:
            return 'B';
        case Colour::PURPLE:
            return 'P';
        default:
            return '*';
    }
}
std::string Shape::colourToString(Colour c) {
    switch (c) {
        case Colour::RED: return "red";
        case Colour::GREEN: return "green";
        case Colour::BLUE: return "blue";
        case Colour::PURPLE: return "purple";
        default: return "unknown";
    }
}

std::string Shape::fillToString(FillStat f) {
    switch (f) {
        case FillStat::FILLED: return "filled";
        case FillStat::FRAME: return "frame";
        default: return "unknown";
    }
}

int Shape :: getId() const {
    return id;
}
Colour Shape :: getColour() const {
    return colour;
};
FillStat Shape :: getFill() const {
    return fill;
};

