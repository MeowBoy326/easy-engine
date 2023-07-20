#pragma once

#include <Core_api.h>
#include <Core/h/Color.h>

namespace easy::graphics::core {
    typedef float VertexUnitType ;

    class CORE_EXPORT Vertex {
    public:
        static const int POSITION_ELEMENTS = 3;
        static const int COLOR_ELEMENTS = 4;

        Vertex() = default;
        Vertex(const Vertex &) = default;
        Vertex(Vertex&&) = default;
        Vertex(float x, float y, float z, const Color& color);
        Vertex(float x, float y, float z = 0);

        Vertex& operator=(const Vertex&) = default;
        Vertex& operator=(Vertex&&) = default;

        VertexUnitType* GetRaw();

        float& X();
        float& Y();
        float& Z();

        Color& Color();

    private:
        float x_ = 0;
        float y_ = 0;
        float z_ = 0;
        core::Color color_;
    };
}
