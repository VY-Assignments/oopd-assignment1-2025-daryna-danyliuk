#include "Board.h"
#include "Shape.h"
#include <string>
#include <iostream>
#include <sstream>

int clInterface() {
    std::string input;
    std::cout << "Input sizes of blackboard (e.g.40x30):\n>" << std::endl;
    std::getline(std::cin, input);

    size_t spliter_pos = input.find('x');
    if (spliter_pos == std::string::npos) {
        std::cout << "Invalid format" << std::endl;
        return 0;
    }

    int width = std::stoi(input.substr(0, spliter_pos));
    int height = std::stoi(input.substr(spliter_pos + 1));

    Board board(width, height);

    while (true) {
        std::cout << "\nPress 'help' to open the manual" << std::endl;
        std::cout << "Enter a command:\n> ";
        std::getline(std::cin, input);


        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) continue;

        if (tokens[0] == "help") {
            std::cout << "Welcome to the blackboard!\n"
                     "Thank you for using our service\n"
                     "At the very beginning you have already entered the size of your blackboard — this is your space for creation!\n"
                     "Available commands:\n"
                     "help - show this manual\n"
                     "draw - draw the blackboard\n"
                     "list - list all shapes\n"
                     "shapes - show available shapes\n"
                     "add - add shape (parameters)\n"
                     "select - select shape by id or coordinates\n"
                     "remove - remove selected shape\n"
                     "edit - change parameters of selected shape\n"
                     "paint - change color of selected shape\n"
                     "move - move selected shape\n"
                     "clear - clear the blackboard\n"
                     "save - save blackboard to file\n"
                     "load - load blackboard from file\n"
                     "exit - exit the program\n";
        }
        else if (tokens[0] == "draw") {
            board.drawAll();
        }
        else if (tokens[0] == "clear") {
            board.clear();
            std::cout << "Board successfully cleared\n";
        }
        else if (tokens[0] == "select" && tokens.size() >= 2) {
            if (tokens.size() == 2) {
                try {
                    int id = std::stoi(tokens[1]);
                    if (board.selectShapeById(id)) {
                        std::cout << "Selected: " << board.getSelectedShapeInfo() << std::endl;
                    } else {
                        std::cout << "Shape with ID " << id << " not found" << std::endl;
                    }
                } catch (...) {
                    std::cout << "Invalid ID format" << std::endl;
                }
            }
            else if (tokens.size() == 3) {
                try {
                    int x = std::stoi(tokens[1]);
                    int y = std::stoi(tokens[2]);
                    if (board.selectShapeByCoordinates(x, y)) {
                        std::cout << "Selected shape at (" << x << "," << y << "): "
                                  << board.getSelectedShapeInfo() << std::endl;
                    } else {
                        std::cout << "No shape found at coordinates (" << x << "," << y << ")" << std::endl;
                    }
                } catch (...) {
                    std::cout << "Invalid coordinates format" << std::endl;
                }
            }
        }
        else if (tokens[0] == "paint" && tokens.size() == 2) {
            Colour newColour;
            if (tokens[1] == "red") newColour = Colour::RED;
            else if (tokens[1] == "green") newColour = Colour::GREEN;
            else if (tokens[1] == "blue") newColour = Colour::BLUE;
            else if (tokens[1] == "purple") newColour = Colour::PURPLE;
            else {
                std::cout << "Unknown color: " << tokens[1] << std::endl;
                continue;
            }

            if (board.paintSelectedShape(newColour)) {
                std::cout << "Shape paintd\n" << tokens[1] << std::endl;
            } else {
                std::cout << "No shape selected.\nUse 'select' command first\n" << std::endl;
            }
        }
        else if (tokens[0] == "move" && tokens.size() == 3) {
            try {
                int newX = std::stoi(tokens[1]);
                int newY = std::stoi(tokens[2]);
                if (board.moveSelectedShape(newX, newY)) {
                    std::cout << "Shape moved to (" << newX << "," << newY << ")" << std::endl;
                } else {
                    std::cout << "No shape selected. Use 'select' command first\n" << std::endl;
                }
            } catch (...) {
                std::cout << "Invalid coordinates format\n" << std::endl;
            }
        }
        else if (tokens[0] == "info") {
            std::cout << board.getSelectedShapeInfo() << std::endl;
        }
        else if (tokens[0] == "list") {
            board.listAllShapes();
        }
        else if (tokens[0] == "remove") {
            if (board.removeSelectedShape()) {
                std::cout << "Selected shape removed\n" << std::endl;
            } else {
                std::cout << "No shape selected. Use 'select' command first\n" << std::endl;
            }
        }
        else if (tokens[0] == "exit") {
            break;
        }
        else if (tokens[0] == "add") {
            if (tokens.size() < 4) {
                std::cout << "Invalid add command. Usage: add <fill|frame> <color> <shape> <coordinates>" << std::endl;
                continue;
            }
        }
        else {
            std::cout << "Unknown command\n"
                         "Type 'help' to see available commands\n";
        }
    }

    return 0;
}