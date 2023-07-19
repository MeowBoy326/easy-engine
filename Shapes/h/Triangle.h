#pragma once

#include <Shapes_api.h>

#include <Shapes/h/Shape.h>

namespace easy::graphics::shapes {

    class SHAPES_EXPORT Triangle : public Shape {
    public:
        Triangle();
        Triangle(const Triangle&) = default;
        Triangle(Triangle&&) = default;
        Triangle(const core::Vertex& p1, const core::Vertex& p2, const core::Vertex& p3);

        const core::Vertex& P1() const;
        const core::Vertex& P2() const;
        const core::Vertex& P3() const;

        core::Vertex& P1();
        core::Vertex& P2();
        core::Vertex& P3();

        void Draw() override;
    };
}
