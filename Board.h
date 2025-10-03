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
    int IdCounter = 1;
    Shape* selectedShape = nullptr;
    std::vector<std::vector<char>> canvas;
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    void bringToFront(Shape* shape);
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
    bool editSelectedShape(const std::string& property, const std::vector<std::string>& args);
    std::string getSelectedShapeInfo();
    void listAllShapes();
    int getIdCounter();

};



#endif //BOARD_H
