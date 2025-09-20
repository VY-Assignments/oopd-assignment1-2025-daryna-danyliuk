#ifndef SHAPE_H
#define SHAPE_H
#include "Board.h"

enum class colour {
    GREEN,
    RED,
    BLUE,
    PURPLE
};

enum class fillStat {
    FILLED,
    FRAME
};

class Shape {
protected:
    int id = 0;
    int xCoord = 0;
    int yCoord = 0;

public:
    virtual void draw(Board&) = 0;
    virtual void edit() = 0;
    virtual void move(int newX, int newY) = 0;
    virtual void paint(enum colour) = 0;
    virtual ~Shape() = default;
};



#endif //SHAPE_H
