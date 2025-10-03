#include "Circle.h"
#include "Shape.h"
#include "Board.h"

Circle::Circle(int id, int x, int y, int r, Colour c, FillStat f)
    :Shape(id, x, y, c, f), radius(r){}

void Circle :: draw(Board& board) {
    if (radius <= 0) {
        std::cout << "Radius must be positive" << std::endl;
        return;
    }
    char symbol = colourToChar(this->colour);
    switch (fill) {
        case FillStat::FRAME: {
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
        }
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

bool Circle::containsPoint(int x, int y) const {
    int dx = x - xCoord;
    int dy = y - yCoord;
    int squaredDistance = dx*dx + dy*dy;

    switch (fill) {
        case FillStat::FRAME:
            return abs(squaredDistance - radius*radius) <= 1;
        case FillStat::FILLED:
            return squaredDistance <= radius*radius;
    }
    return false;
}

void Circle::move(int newX, int newY) {
    xCoord = newX;
    yCoord = newY;
}

void Circle::paint(Colour newColour) {
    colour = newColour;

}

std::string Circle::info() const {
    return "Circle " + std::to_string(id) + " at (" +
           std::to_string(xCoord) + "," + std::to_string(yCoord) +
           ") " + colourToString(colour) + " " + fillToString(fill) +
           " " + std::to_string(radius);
}
bool Circle::edit(const std::vector<int>& params) {
    if (params.empty()) {
        std::cerr << "Error: edit requires positive integer parameter (radius)\n";
        return false;
    }
    if (params[0] <= 0) {
        std::cerr << "Error: height must be positive\n";
        return false;
    }
    radius = params[0];
    return true;
}

