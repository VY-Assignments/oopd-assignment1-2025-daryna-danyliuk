#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Board.h"


class Circle : public Shape {
private:
    int radius;
    int centre;
    Colour colour;
    FillStat fill;
public:
    Circle( int id, int x, int y, int r, int cr, Colour c, FillStat f);
    
    void draw(Board& board) override;
    void edit() override;
    void move(int newX, int newY) override;
    void paint(Colour c) override;
    std::string info() override;

};



#endif //CIRCLE_H
