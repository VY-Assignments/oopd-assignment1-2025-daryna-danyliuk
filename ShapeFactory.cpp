#include "Board.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Diamond.h"
#include <string>
#include <iostream>
#include <memory>

std::unique_ptr<Shape> createShape(const std::string& type,int id, int x, int y,const std::vector<int>& params, Colour colour, FillStat fill) {
    if (type == "rectangle" && params.size() == 2) {
        return std::make_unique<Rectangle>(id, x, y, params[0], params[1], colour, fill);
    }
    else if (type == "circle" && params.size() == 1) {
        return std::make_unique<Circle>(id, x, y, params[0], colour, fill);
    }
    else if (type == "triangle" && params.size() == 1) {
        return std::make_unique<Triangle>(id, x, y, params[0], colour, fill);
    }
    else if (type == "diamond" && params.size() == 2) {
        return std::make_unique<Diamond>(id, x, y, params[0], params[1], colour, fill);
    }
    else {
        return nullptr;
    }
}

