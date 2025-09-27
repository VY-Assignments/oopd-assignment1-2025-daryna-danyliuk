#include "Rectangle.h"
#include "Shape.h"
#include "Board.h"

Rectangle::Rectangle(int id, int x, int y, int w, int h, Colour c, FillStat f)
    :Shape(id, x, y, c, f), width(w), height(h) {}

void Rectangle :: draw(Board& board) {
    if (width <= 0 || height <= 0) {
        std::cout << "Width and height must be positive" << std::endl;
        return;
    }
    char symbol = colourToChar(this->colour);
    switch (fill) {
        case FillStat::FRAME:
            for (int xFrame = 0; xFrame < width; ++xFrame) {
                board.setCell(xCoord + xFrame ,yCoord, symbol);
                board.setCell(xCoord + xFrame ,yCoord + height - 1,symbol);
            }
            for (int yFrame = 0; yFrame < height; ++yFrame) {
                board.setCell(xCoord, yCoord + yFrame, symbol);
                board.setCell(xCoord + width - 1, yCoord + yFrame, symbol);
            }
            break;
        case FillStat::FILLED:
            for (int xFilled = 0; xFilled < width; ++xFilled) {
                for (int yFilled = 0; yFilled < height; ++yFilled) {
                    board.setCell(xCoord + xFilled, yCoord + yFilled,symbol);
                }
            }
            break;
    }
}
bool Rectangle::containsPoint(int x, int y) const {
    switch (fill) {
        case FillStat :: FRAME:
            if ((y == yCoord || y == yCoord + height -1)  && x >= xCoord && x < xCoord + width) {
                return true;
            }
            if ((x == xCoord || x == xCoord + width - 1) && y >= yCoord && y < yCoord + height) {
                return true;
                }
            break;
        case FillStat :: FILLED:
            if ( xCoord <= x  && x < xCoord + width &&
                yCoord <= y && y < yCoord + height) {
                return true;
            }
            break;
    }
    return false;
}
void Rectangle::edit() {
}

void Rectangle::move(int newX, int newY) {
    xCoord = newX;
    yCoord = newY;
}

void Rectangle::paint(Colour newColour) {
    colour = newColour;

}

std::string Rectangle::info() const {
    return "Rectangle " + std::to_string(id) + " at (" +
           std::to_string(xCoord) + "," + std::to_string(yCoord) +
           ") " + colourToString(colour) + " " + fillToString(fill) +
           " " + std::to_string(width) + "x" + std::to_string(height);
}