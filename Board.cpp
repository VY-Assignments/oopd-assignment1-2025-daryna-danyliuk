#include "Board.h"
#include "Shape.h"
#include <vector>
#include <iostream>

Board::Board(int w, int h)
    : width(w), height(h), canvas(h, std::vector<char>(w,' ')){}

void Board::print(){
    for (int i = 0; i<height; i++ ) {
        for (int j = 0; j<width; j++ ) {
            std::cout << canvas[i][j];
        }
        std::cout << "\n";
    }
}

void Board::clear() {
    for (int i = 0; i<height; i++ ) {
        for (int j = 0; j<width; j++ ) {
            canvas[i][j] = ' ';
        }
    }
}
bool Board::isInside(int x, int y) const{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool Board::setCell(int x, int y, char ch) {
    if (isInside(x, y)) {
        canvas[y][x] = ch;
        return true;
    }
    else {
        return false;
    }
}
int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

