#ifndef SHAPE_H
#define SHAPE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
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
    static char colourToChar(Colour c);;
    static std::string colourToString(Colour c);
    static std::string fillToString(FillStat f);
    int id = 0;
    int xCoord = 0;
    int yCoord = 0;
    Colour colour;
    FillStat fill;

public:
    Shape(int id, int x, int y, Colour c, FillStat f) : id(id), xCoord(x), yCoord(y), colour(c), fill(f){}
    virtual void draw(Board&) = 0;
    virtual void move(int newX, int newY) = 0;
    virtual void paint(Colour) = 0;
    virtual std::string info() const = 0;
    virtual bool containsPoint(int x, int y) const = 0;
    virtual ~Shape() = default;
    int getId() const;
    virtual void edit (const std::vector<int>& params) = 0;
    Colour getColour() const;
    FillStat getFill() const;

};

#endif //SHAPE_H
