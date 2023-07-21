#pragma once

#include <Shapes_api.h>

#include <Shapes/h/Shape.h>

namespace easy::shapes {

    class SHAPES_EXPORT Rectangle : public Shape {
    public:
        Rectangle();
        Rectangle(const Rectangle&) = default;
        Rectangle(Rectangle&&) = default;
        Rectangle(const core::Position& position, float width, float height);

        void Draw() override;
    };
}
