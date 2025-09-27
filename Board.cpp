#include "Board.h"
#include <algorithm>
#include "Shape.h"
#include <vector>
#include <iostream>
#include <memory>

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
void Board::addShape(std::unique_ptr<Shape> shape) {
    shapes.push_back(std::move(shape));
}
void Board:: drawAll() {
    clear();
    for (std::unique_ptr<Shape>& shape : shapes) {
        shape->draw(*this);
    }
    print();
}

Shape* Board:: findById(int Id) {
    for (std::unique_ptr<Shape>& shape : shapes) {
        if (shape -> getId() == Id)
        {
            return shape.get();

        }
    }
    return nullptr;
}

void Board :: removeShape(int Id) {
    shapes.erase(
    std::remove_if(shapes.begin(), shapes.end(),
        [Id](const std::unique_ptr<Shape>& shape) {
            return shape->getId() == Id;
        }),
        shapes.end()
        );
}
