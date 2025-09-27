#include "Diamond.h"
#include "Shape.h"
#include "Board.h"

Diamond::Diamond(int id, int x, int y, int w, int h, Colour c, FillStat f)
    :Shape(id, x, y), width(w), height(h), colour(c), fill(f) {}

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