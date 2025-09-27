#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Board.h"


class Rectangle : public Shape {
private:
    int width;
    int height;
    Colour colour;
    FillStat fill;

public:
    Rectangle(int id, int x, int y, int w, int h, Colour c, FillStat f);
    void draw(Board& board) override;
    void edit() override;
    void move(int newX, int newY) override;
    void paint(Colour c) override;
    bool containsPoint( int x, int y) const override;
    std::string info() override;
};

#endif // RECTANGLE_H