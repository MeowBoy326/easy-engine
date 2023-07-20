#pragma once

#include <Core_api.h>

namespace easy::graphics::core {
    class CORE_EXPORT Position {
    public:
        Position() = default;
        Position(const Position&) = default;
        Position(Position&&) = default;
        Position(float x, float y, float z);
        Position(float x, float y);

        Position& operator=(const Position&) = default;
        Position& operator=(Position&&) = default;

        Position Add(const Position& other) const;
        Position Substract(const Position& other) const;

        friend Position operator+(const Position& a, const Position& b);
        friend Position operator-(const Position& a, const Position& b);

        float x = 0;
        float y = 0;
        float z = 0;
    };
}
