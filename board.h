#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "point.h"

// Increase amount of new lines for input
constexpr int g_consoleLines{ 25 };

class Board {
private:
    static constexpr int s_size { 4 };
    static constexpr int randomisation{ 100 };
    std::array<std::array<Tile, s_size>, s_size> board;

public:
    Board() : board{} {
        int count{1};
        for (int i = 0; i < s_size; ++i) {
            for (int j = 0; j < s_size; ++j) {
                if (i == s_size - 1 && j == s_size - 1) {
                    board[i][j] = Tile{0};
                    continue;
                }
                board[i][j] = Tile{count};
                count++;
            }
        }
    }

    Point locateEmpty() {
        for (int i = 0; i < s_size; ++i) {
            for (int j = 0; j < s_size; ++j) {
                if (board[i][j].isEmpty()) {
                    return Point{j, i};
                }
            }
        }
        return Point{};
    }

    bool moveTile(const Direction& d) {
        Point p{ locateEmpty() };
        Point tileToBeMoved{ p.getAdjacentPoint(d) };
        int x{ tileToBeMoved.getX() };
        int y{ tileToBeMoved.getY() };

        if (std::min(x, y) < 0 || x >= s_size || y >= s_size) {
            return false;
        }
        std::swap(board[p.getY()][p.getX()], board[y][x]);

        return true;
    }

    void randomiseBoard() {
        for (int i = 0; i < randomisation; ++i)
            moveTile(Direction::getRandomDirection());
    }

    bool solved() {
        Board comparison{};
        for (int i = 0; i < s_size; ++i) {
            for (int j = 0; j < s_size; ++j) {
                if (board[i][j].getNum() != comparison.board[i][j].getNum()) {
                    return false;
                }
            }
        }
        return true;
    }

    friend std::ostream& operator<< (std::ostream& out, const Board& b);
};

std::ostream& operator<< (std::ostream& out, const Board& b) {
    for (int i = 0; i < g_consoleLines; ++i)
        std::cout << '\n';

    for (int i = 0; i < b.s_size; ++i) {
        for (int j = 0; j < b.s_size; ++j) {
            if (b.board[i][j].getNum() == -1) {
                out << "   ";
                continue;
            }
            if (b.board[i][j].getNum() >= 1 && b.board[i][j].getNum() <= 9) {
                out << " ";
            }
            out << b.board[i][j].getNum() << " ";
        }
        out << "\n";
    }
    return out;
}

#endif