#include <Core/h/Position.h>

namespace easy::graphics::core {
    Position::Position(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    Position::Position(float x, float y) : x(x), y(y)
    {
    }

    Position Position::Add(const Position& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Position Position::Substract(const Position& other) const 
    {
        return { x - other.x, y - other.y, z - other.z };
    }

    Position operator+(const Position& a, const Position& b)
    {
        return a.Add(b);
    }

    Position operator-(const Position& a, const Position& b)
    {
        return a.Substract(b);
    }
}
