#ifndef SHAPE_H
#define SHAPE_H

#pragma once
#include <iostream>
#include <string>
class Board;

enum class Colour {
    GREEN,
    RED,
    BLUE,
    PURPLE
};

enum class FillStat {
    FILLED,
    FRAME
};

class Shape {
protected:
    static char colourToChar(Colour c);
    static char filledToChar(FillStat f);
    int id = 0;
    int xCoord = 0;
    int yCoord = 0;

public:
    Shape(int id, int x, int y) : id(id), xCoord(x), yCoord(y) {}
    virtual void draw(Board&) = 0;
    virtual void edit() = 0;
    virtual void move(int newX, int newY) = 0;
    virtual void paint(Colour) = 0;
    virtual std::string info() = 0;
    int getId() const;
    virtual ~Shape() = default;
};



#endif //SHAPE_H
