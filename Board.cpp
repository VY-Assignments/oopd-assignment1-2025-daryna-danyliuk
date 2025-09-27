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
bool Board::selectShapeByCoordinates(int x, int y) {
    for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
        if ((*it)->containsPoint(x, y)) {
            selectedShape = it->get();
            return true;
        }
    }
    return false;
}

bool Board::removeSelectedShape() {
    if (selectedShape == nullptr) {
        return false;
    }
    int idToRemove = selectedShape->getId();
    selectedShape = nullptr;
    shapes.erase(
        std::remove_if(shapes.begin(), shapes.end(),
            [idToRemove](const std::unique_ptr<Shape>& shape) {
                return shape->getId() == idToRemove;
            }),
        shapes.end()
    );
    return true;
}
bool Board::selectShapeById(int id) {
    selectedShape = findById(id);
    return selectedShape != nullptr;
}

bool Board::moveSelectedShape(int newX, int newY) {
    if (selectedShape == nullptr) {
        return false;
    }
    if (isInside(newX, newY) == false) {
        return false;
    }

    selectedShape->move(newX, newY);
    return true;
}

bool Board::paintSelectedShape(Colour newColour) {
    if (selectedShape == nullptr) {
        return false;
    }
    selectedShape->paint(newColour);
    return true;
}

std::string Board::getSelectedShapeInfo() {
    if (selectedShape == nullptr) {
        return "No shape selected\n";
    }
    return selectedShape->info();
}
void Board::listAllShapes() {
    if (shapes.empty()) {
        std::cout << "No shapes on the board\n" << std::endl;
        return;
    }
    for (const auto& shape : shapes) {
        std::cout << shape->info()<< std::endl;
    }
}
