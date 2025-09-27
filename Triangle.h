#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape {
private:
    int height;

public:
    Triangle(int id, int x, int y, int h, Colour colour, FillStat fill);
    void draw(Board& board) override;
    void move(int newX, int newY) override;
    void paint(Colour) override;
    bool containsPoint( int x, int y) const override;
    void edit(const std::vector<int> &params) override;
    std::string info() const override;
};

#endif //TRIANGLE_H
