#pragma once

#include <Core_api.h>
#include <Core/h/Position.h>
#include <Core/h/Color.h>

namespace easy::core {
    typedef float VertexUnitType ;

    class CORE_EXPORT Vertex {
    public:
        static const int POSITION_ELEMENTS = 3;
        static const int COLOR_ELEMENTS = 4;

        Vertex() = default;
        Vertex(const Vertex &) = default;
        Vertex(Vertex&&) = default;
        Vertex(const Position& position, const Color& color);
        Vertex(const Position& position);

        Vertex& operator=(const Vertex&) = default;
        Vertex& operator=(Vertex&&) = default;

        VertexUnitType* GetRaw();

        core::Position& Position();
        const core::Position& Position() const;

        core::Color& Color();
        const core::Color& Color() const;

    private:
        core::Position position_;
        core::Color color_;
    };
}
