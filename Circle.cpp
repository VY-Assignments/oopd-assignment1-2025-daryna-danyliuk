#include "Circle.h"
#include "Shape.h"
#include "Board.h"

Circle::Circle(int id, int x, int y, int r, Colour c, FillStat f)
    :Shape(id, x, y), radius(r), colour(c), fill(f) {}

void Circle :: draw(Board& board) {
    if (radius <= 0) {
        std::cout << "Radius must be positive" << std::endl;
        return;
    }
    char symbol = colourToChar(this->colour);
    switch (fill) {
        case FillStat::FRAME:
            int frameBorder = 1;
            for (int y = yCoord  - radius; y <= yCoord + radius; ++y ) {
                for (int x = xCoord - radius; x <= xCoord + radius; ++x) {
                    int dx = x - xCoord;
                    int dy = y - yCoord;
                    int distanceSquared = dx * dx + dy * dy;
                    if (abs(distanceSquared - radius*radius)<= frameBorder) {
                        board.setCell(x, y, symbol);
                    }
                }
            }
            break;
        case FillStat::FILLED:
            for (int y = yCoord  - radius; y <= yCoord + radius; ++y ) {
                for (int x = xCoord - radius; x <= xCoord + radius; ++x) {
                    int dx = x  - xCoord;
                    int dy = y - yCoord;
                    int distanceSquared = dx * dx + dy * dy;
                    if (distanceSquared <= radius*radius) {
                        board.setCell(x, y, symbol);
                    }
                }
            }
            break;
    }
}

