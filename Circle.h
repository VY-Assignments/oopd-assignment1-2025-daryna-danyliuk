#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Board.h"


class Circle : public Shape {
private:
    int radius;
public:
    Circle( int id, int x, int y, int r, Colour c, FillStat f);
    void draw(Board& board) override;
    void edit() override;
    void move(int newX, int newY) override;
    void paint(Colour c) override;
    bool containsPoint( int x, int y) const override;
    std::string info() const override;

};

#endif //CIRCLE_H
