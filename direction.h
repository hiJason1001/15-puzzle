#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction {
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        maxDirections,
    };
    Direction(Type type)
        :m_type(type)
    {
    }

    Type getType() const
    {
        return m_type;
    }

    Direction operator-() const {
        switch (m_type)
        {
        case up:    return Direction{ down };
        case down:  return Direction{ up };
        case left:  return Direction{ right };
        case right: return Direction{ left };
        default:    break;
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ up };
    }

    static Direction getRandomDirection() {
        Type random{ static_cast<Type>(Random::get(0, Type::maxDirections - 1)) };
        return Direction{ random };
    }

private:
    Type m_type{};
};

std::ostream& operator<< (std::ostream& out, const Direction& d) {
    switch (d.getType()) {
    case Direction::up:     return (out << "up");
    case Direction::down:   return (out << "down");
    case Direction::left:   return (out << "left");
    case Direction::right:  return (out << "right");
    default:                break;
    }

    assert(0 && "Unsupported direction was passed!");
    return (out << "unknown direction");
}



#endif