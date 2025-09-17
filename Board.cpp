#include "Board.h"
#include <vector>
#include <iostream>

Board::Board(int w, int h)
    : height(h), width(w), canvas(h, std::vector<char>(w,' ')){}

void Board::print(){
    for (int i = 0; i<height; i++ ) {
        for (int j = 0; j<width; j++ ) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::clear() {
    for (int i = 0; i<height; i++ ) {
        for (int j = 0; j<width; j++ ) {
            canvas[i][j] = ' ';
        }
    }
}