#ifndef BOARD_H
#define BOARD_H

#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class Shape;

class Board {
private:
    int width;
    int height;
    Shape* selectedShape = nullptr;
    std::vector<std::vector<char>> canvas;
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    bool isInside(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    bool setCell(int x, int y, char ch);
    Board (int w, int h);
    void clear();
    void print();
    void addShape(std::unique_ptr<Shape> shapes);
    void drawAll();
    Shape* findById(int Id);
    bool selectShapeByCoordinates(int x, int y);
    bool removeSelectedShape();
    bool moveSelectedShape(int newX, int newY);
    bool selectShapeById(int Id);
    bool paintSelectedShape(Colour newColour);
    std::string getSelectedShapeInfo();
    void Board::listAllShapes();

};



#endif //BOARD_H
