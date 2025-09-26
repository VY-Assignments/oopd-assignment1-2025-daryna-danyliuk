#include "Triangle.h"
#include "Shape.h"
#include "Board.h"
#include <algorithm>

Triangle::Triangle(int id, int x, int y, int h, Colour c, FillStat f)
    :Shape(id, x, y), height(h), colour(c), fill(f) {}

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
