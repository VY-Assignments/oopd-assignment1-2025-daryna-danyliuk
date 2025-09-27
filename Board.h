#ifndef BOARD_H
#define BOARD_H

#pragma once
#include <vector>
#include <memory>

class Shape;

class Board {
private:
    int width;
    int height;
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
    void removeShape(int Id);
};



#endif //BOARD_H
