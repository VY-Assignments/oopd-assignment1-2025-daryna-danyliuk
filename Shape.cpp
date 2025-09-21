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
char Shape::filledToChar(FillStat f) {
    switch (f) {
        case FillStat::FILLED:
            return 'F';
        case FillStat::FRAME:
            return 'NF';
    }
}
