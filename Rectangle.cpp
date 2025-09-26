#include "Rectangle.h"
#include "Shape.h"
#include "Board.h"

Rectangle::Rectangle(int id, int x, int y, int w, int h, Colour c, FillStat f)
    :Shape(id, x, y), width(w), height(h), colour(c), fill(f) {}

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
void Rectangle::edit() {
}

void Rectangle::move(int dx, int dy) {
}

void Rectangle::paint(Colour c) {
}

std::string Rectangle::info() {
}