#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle(int id, int x, int y, int w, int h, Colour c, FillStat f)
    :Shape(id, x, y), width(w), height(h), colour(c), fill(f) {}

void Rectangle :: draw(Board& board) {
    if (width <= 0 || height <= 0) {
        std::cout << "Width and height must be positive." << std::endl;
        return;
    }
    char symbol = colourToChar(this->colour);

}