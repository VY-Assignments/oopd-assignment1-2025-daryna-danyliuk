#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board {
private:
    int height;
    int width;
    std::vector<std::vector<char>> canvas;
public:
    Board (int h, int w);
    void clear();
    void print();
};



#endif //BOARD_H
