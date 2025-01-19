#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
#include "random.h"
#include "direction.h"
#include "tile.h"
#include "board.h"

namespace UserInput {
    void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    char getInput() {
        char command{};
        std::cin >> command;
        ignoreLine();

        while (command != 'w' && command != 'a' && command != 's' && command != 'd' && command != 'q') {
            std::cin >> command;
            ignoreLine();
        }
        return command;
    }

    Direction charToDirection(char ch)
    {
        switch (ch)
        {
        case 'w': return Direction{ Direction::up };
        case 's': return Direction{ Direction::down };
        case 'a': return Direction{ Direction::left };
        case 'd': return Direction{ Direction::right };
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }

    void win() {
        std::cout << "\n\nYou won!\n\n";
    }
    
    void quit() {
        std::cout << "\n\nBye!\n\n";
    }
}


int main()
{
    Board board{};
    board.randomiseBoard();
    std::cout << board;

    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... " << Direction::getRandomDirection() << "\n\n";

    std::cout << "Enter a command: ";
    while (true)
    {
        char ch{ UserInput::getInput() };

        if (ch == 'q')
        {
            UserInput::quit();
            break;
        }

        Direction dir{ UserInput::charToDirection(ch) };

        std::cout << "You entered direction: " << dir << '\n';

        if (board.moveTile(dir)) {
            std::cout << board;
            if (board.solved()) {
                UserInput::win();
                break;
            }
        }
    }

    return 0;
}

