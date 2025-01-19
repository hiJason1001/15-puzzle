#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile {
private:
    int m_number{};

public:
    Tile() = default;
    Tile(int num) : m_number(num == 0 ? -1 : num) {}

    int getNum() const { return m_number; }
    bool isEmpty() const { return m_number == -1; }

    friend std::ostream& operator<< (std::ostream& out, const Tile& t);
};

std::ostream& operator<< (std::ostream& out, const Tile& t) {
    if (t.getNum() > 9) // if two digit number
        out << " " << t.getNum() << " ";
    else if (t.getNum() > 0) // if one digit number
        out << "  " << t.getNum() << " ";
    else if (t.getNum() == 0) // if empty spot
        out << "    ";
    return out;
}

#endif