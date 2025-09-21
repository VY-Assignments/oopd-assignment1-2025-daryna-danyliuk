#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "Shape.h"

class Board {
private:
    int height;
    int width;
    std::vector<std::vector<char>> canvas;
    std::vector<std::unique_ptr<Shape>> shapes;
public:
    bool isInside(int x, int y);
    int getWidth() const;
    int getHeight() const;
    bool setCell(int x, int y, char ch);
    Board (int h, int w);
    void clear();
    void print();
};



#endif //BOARD_H
