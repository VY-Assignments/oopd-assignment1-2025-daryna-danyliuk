#ifndef DIAMOND_H
#define DIAMOND_H
#include "Shape.h"
#include "Board.h"



class Diamond : public Shape {
private:
    int width;
    int height;
    Colour colour;
    FillStat fill;

public:
    Diamond (int id, int x, int y, int w, int h, Colour c, FillStat f);
    void draw(Board& board) override;
    void edit() override;
    void move(int newX, int newY) override;
    void paint(Colour c) override;
    std::string info() override;
    bool isInDiamond(int x, int y);
    bool containsPoint( int x, int y) const override;
};



#endif //DIAMOND_H
