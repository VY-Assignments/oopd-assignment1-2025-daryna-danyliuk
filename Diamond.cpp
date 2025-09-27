#include "Diamond.h"
#include "Shape.h"
#include "Board.h"
#include <cmath>


Diamond::Diamond(int id, int x, int y, int w, int h, Colour c, FillStat f)
    :Shape(id, x, y, c ,f), width(w), height(h){}

bool Diamond :: isInDiamond(int x, int y) {
    int dx = abs(x - xCoord);
    int dy = abs(y - yCoord);
    return (dx * 2.0 / width + dy * 2.0 / height <= 1.0);
}
void Diamond :: draw(Board& board) {
    if (width <= 0 || height <= 0) {
        std::cout << "Width and height must be positive" << std::endl;
        return;
    }
    char symbol = colourToChar(this->colour);
    int halfWidth = width/2;
    int halfHeight = height/2;
    for (int j = yCoord - halfHeight; j <= yCoord + halfHeight;  ++j) {
        for ( int i = xCoord - halfWidth; i <= xCoord + halfWidth; ++i) {
            bool isEndPoint = false;
            if (!isInDiamond(i-1, j) || !isInDiamond(i+1, j) ||
                !isInDiamond(i, j-1) || !isInDiamond(i, j+1)) {
                isEndPoint = true;
                }
            int dx = abs(i -xCoord);
            int dy = abs(j - yCoord);
            if (isInDiamond(i, j)) {
                switch (fill) {
                    case FillStat::FRAME:
                        if (isEndPoint) {
                            board.setCell(i, j, symbol);
                        }
                        break;
                    case FillStat::FILLED:
                        board.setCell(i, j, symbol);
                        break;
                }
            }
        }
    }
}

bool Diamond::containsPoint(int x, int y) const {
    int dx = abs(x - xCoord);
    int dy = abs(y - yCoord);

    double value = (dx * 2.0 / width) + (dy * 2.0 / height);
    switch (fill) {
        case FillStat :: FRAME:
            return fabs(value - 1.0) < 0.1;
        case FillStat :: FILLED:
            return value <= 1;
    }
    return false;
}

void Diamond::move(int newX, int newY) {
    xCoord = newX;
    yCoord = newY;
}

void Diamond::paint(Colour newColour) {
    colour = newColour;
}

std::string Diamond::info() const {
    return "RDiamond " + std::to_string(id) + " at (" +
           std::to_string(xCoord) + "," + std::to_string(yCoord) +
           ") " + colourToString(colour) + " " + fillToString(fill) +
           " " + std::to_string(width) + "x" + std::to_string(height);;
}
void Diamond::edit(const std::vector<int> &params) {
    if (params.size() <= 2) {
        width  = params[0];
        height = params[1];
    }
}
