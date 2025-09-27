#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape {
private:
    int height;
    Colour colour;
    FillStat fill;

public:
    Triangle(int id, int x, int y, int h, Colour colour, FillStat fill);
    void draw(Board& board) override;
    void edit() override;
    void move(int newX, int newY) override;
    void paint(Colour) override;
    bool containsPoint( int x, int y) const override;
    std::string info() override;
};

#endif //TRIANGLE_H
