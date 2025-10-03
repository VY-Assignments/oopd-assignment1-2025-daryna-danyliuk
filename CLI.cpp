#include "Board.h"
#include "Shape.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

std::unique_ptr<Shape> createShape(const std::string& type, int id, int x, int y, const std::vector<int>& params, Colour colour, FillStat fill);

int clInterface() {
    std::string input;
    std::cout << "Input sizes of blackboard (e.g.40x30):\n> ";
    std::getline(std::cin, input);

    size_t spliter_pos = input.find('x');
    if (spliter_pos == std::string::npos) {
        std::cout << "Invalid format" << std::endl;
        return 1;
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

        const std::string& cmd = tokens[0];

        if (cmd == "help") {
            std::cout << "Available commands:\n"
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
        else if (cmd == "draw") {
            board.drawAll();
        }
        else if (cmd == "clear") {
            board.clear();
            std::cout << "Board successfully cleared\n";
        }
        else if (cmd == "exit") {
            break;
        }
        else if (cmd == "list") {
            board.listAllShapes();
        }
        else if (cmd == "select") {
            if (tokens.size() == 2) {
                try {
                    int id = std::stoi(tokens[1]);
                    if (board.selectShapeById(id)) {
                        std::cout << "Shape with id " << id << " selected.\n";
                    } else {
                        std::cout << "Shape with id " << id << " not found.\n";
                    }
                } catch (...) {
                    std::cout << "Invalid id format.\n";
                }
            }
            else if (tokens.size() == 3) {
                try {
                    int x = std::stoi(tokens[1]);
                    int y = std::stoi(tokens[2]);
                    if (board.selectShapeByCoordinates(x, y)) {
                        std::cout << "Shape at coordinates (" << x << "," << y << ") selected.\n";
                    } else {
                        std::cout << "No shape found at given coordinates.\n";
                    }
                } catch (...) {
                    std::cout << "Invalid coordinates format.\n";
                }
            }
            else {
                std::cout << "Usage: select <id> OR select <x> <y>\n";
            }
        }
        else if (cmd == "move") {
            if (tokens.size() != 3) {
                std::cout << "Usage: move <dx> <dy>\n";
            } else {
                try {
                    int dx = std::stoi(tokens[1]);
                    int dy = std::stoi(tokens[2]);
                    if (board.moveSelectedShape(dx, dy)) {
                        std::cout << "Selected shape moved to (" << dx << "," << dy << ")\n";
                    } else {
                        std::cout << "No shape is currently selected.\n";
                    }
                } catch (...) {
                    std::cout << "Invalid coordinates format.\n";
                }
            }
        }
        else if (cmd == "remove") {
            if (board.removeSelectedShape()) {
                std::cout << "Selected shape removed\n";
            }
            else {
                std::cout << "No shape is currently selected.\n";
            }
        }
        else if (cmd == "info") {
            std::cout << board.getSelectedShapeInfo();
        }
        else if (cmd == "paint") {
            if (tokens.size() < 2) {
                std::cout << "Usage: paint <color>\n";
                continue;
            }
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
                std::cout << "Shape painted.\n";
            } else {
                std::cout << "No shape is currently selected.\n";
            }
        }
        else if (cmd == "edit") {
            if (tokens.size() < 2) {
                std::cout << "Usage: edit <params>\n";
                continue;
            }
            std::vector<std::string> args(tokens.begin() + 1, tokens.end());
            if (board.editSelectedShape(args)) {
                std::cout << "Shape edited successfully.\n";
            } else {
                std::cout << "Failed to edit shape.\nCheck property and arguments.\n";
            }
        }
        else if (cmd == "add") {
            if (tokens.size() < 5) {
                std::cout << "Invalid add command\nUsage: add <fill|frame> <color> <shape> <params...>" << std::endl;
                continue;
            }

            FillStat fill;
            if (tokens[1] == "fill") fill = FillStat::FILLED;
            else if (tokens[1] == "frame") fill = FillStat::FRAME;
            else {
                std::cout << "Invalid fill type. Use 'fill' or 'frame'\n";
                continue;
            }

            Colour colour;
            if (tokens[2] == "red") colour = Colour::RED;
            else if (tokens[2] == "green") colour = Colour::GREEN;
            else if (tokens[2] == "blue") colour = Colour::BLUE;
            else if (tokens[2] == "purple") colour = Colour::PURPLE;
            else {
                std::cout << "Unknown color: " << tokens[2] << std::endl;
                continue;
            }

            std::vector<int> params;
            try {
                for (size_t i = 4; i < tokens.size(); ++i) {
                    params.push_back(std::stoi(tokens[i]));
                }
            } catch (...) {
                std::cout << "Invalid parameters format\n";
                continue;
            }

            auto shape = createShape(tokens[3], board.getIdCounter(), 0, 0, params, colour, fill);
            if (shape) {
                board.addShape(std::move(shape));
                std::cout << "Shape added successfully\n";
            } else {
                std::cout << "Failed to create shape. Check parameters.\n";
            }

        }
        else {
            std::cout << "Unknown command. Type 'help' to see available commands.\n";
        }

    }

    return 0;
}
