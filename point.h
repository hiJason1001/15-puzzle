#ifndef POINT_H
#define POINT_H

#include "direction.h"

class Point {
private:
    int m_x{};
    int m_y{};

public:
    Point(int x=0, int y=0) : m_x(x), m_y(y) {}

    Point getAdjacentPoint(const Direction& d) {
        switch (d.getType()) {
        case Direction::up:    return Point{ m_x, m_y - 1 };
        case Direction::down:  return Point{ m_x, m_y + 1 };
        case Direction::left:  return Point{ m_x - 1, m_y };
        case Direction::right: return Point{ m_x + 1, m_y };
        default:    break;
        }
        return Point{};
    }

    int getX() { return m_x; }
    int getY() { return m_y; }

    friend bool operator== (const Point& p1, const Point& p2) { 
        return p1.m_x == p2.m_x && p1.m_y== p2.m_y;
    }

    friend bool operator!= (const Point& p1, const Point& p2) { 
        return !(p1 == p2);
    }
    
};

#endif