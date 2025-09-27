#include "Triangle.h"
#include "Shape.h"
#include "Board.h"
#include <algorithm>

Triangle::Triangle(int id, int x, int y, int h, Colour c, FillStat f)
    :Shape(id, x, y, c, f), height(h) {}

void Triangle :: draw(Board& board) {
    if (height <= 0) {
        std::cout << "Height must be positive" << std::endl;
        return;
    }
    char symbol = colourToChar(colour);
    for (int i = 0; i < height; ++i) {
        int numSymbols = 2 * i +1;
        int leftMost = xCoord - i;
        for (int j = 0; j < numSymbols; ++j) {
            switch (fill) {
                case FillStat::FRAME:
                    if (i == height - 1  || j == 0 || j == numSymbols - 1) {
                        board.setCell(leftMost + j, yCoord + i, symbol);
                    }
                    break;
                case FillStat::FILLED:
                    board.setCell(leftMost + j, yCoord + i, symbol);
            }

        }
    }
}

bool Triangle::containsPoint(int x, int y) const {
    if (y < yCoord || y >= yCoord + height) {
        return false;
    }

    int vertex = y - yCoord;

    int leftMost  = xCoord - vertex;
    int rightMost = xCoord + vertex;

    switch (fill) {
        case FillStat::FRAME:
            if (x == leftMost || x == rightMost || vertex == height - 1) {
                return true;
            }
            else {
                return false;
            }

        case FillStat::FILLED:
            if (x >= leftMost && x <= rightMost) {
                return true;
            }
            else {
                return false;
            }
    }
    return false;
}

void Triangle::edit() {
}

void Triangle::move(int newX, int newY) {
    xCoord = newX;
    yCoord = newY;
}

void Triangle::paint(Colour newColour) {
    colour = newColour;
}

std::string Triangle::info() const {
    return "Triangle " + std::to_string(id) + " at (" +
           std::to_string(xCoord) + "," + std::to_string(yCoord) +
           ") " + colourToString(colour) + " " + fillToString(fill) +
           " " + std::to_string(height);
}

