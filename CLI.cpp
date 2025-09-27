#include "Board.h"
#include "Shape.h"
#include <string>
#include <iostream>

int cliInterface() {
    std::string input;
    std::cout << "Input sizes of blackboard (e.g. 40x30):\n" << std::endl;
    std::getline(std::cin, input);

    size_t x_pos = input.find('x');
    if (x_pos == std::string::npos) {
        std::cout << "Invalid format. Example: 40x30" << std::endl;
        return 1;
    }

    int width = std::stoi(input.substr(0, x_pos));
    int height = std::stoi(input.substr(x_pos + 1));

    Board board(width, height);

    while (true) {
        std::cout << "\nPress 'help' to open the manual" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, input);

        if (input == "help") {
            std::cout << "\nWelcome to the blackboard!\n"
                         "Thank you for using our service\n"
                         "At the very beginning you have already entered the size of your blackboard — this is your space for creation!\n\n"
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
                         "exit - exit the proggram\n";
        }
        else if (input == "draw") {
            board.drawAll();
        }
        else if (input == "clear") {
            board.clear();
            std::cout << "Board cleared.\n";
        }
        else if (input == "exit") {
            break;
        }
        else {
            std::cout << "Unknown command. Type 'help' to see available commands.\n";
        }
    }

    return 0;
}
