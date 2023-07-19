#pragma once

#include <Core_api.h>

namespace easy::graphics::core {
    typedef float VertexUnitType ;

    class CORE_EXPORT Vertex {
    public:
        Vertex() = default;
        Vertex(const Vertex &) = default;
        Vertex(Vertex&&) = default;
        Vertex(float x, float y, float z, float r, float g, float b, float a);
        Vertex(float x, float y, float z = 0);


        Vertex& operator=(const Vertex&) = default;
        Vertex& operator=(Vertex&&) = default;

        VertexUnitType* GetRaw();
        float& GetX();
        float& GetY();
        float& GetZ();

        static const int POSITION_ELEMENTS = 3;
        static const int COLOR_ELEMENTS    = 4;
    private:
        float x_ = 0;
        float y_ = 0;
        float z_ = 0;

        float r_ = 1;
        float g_ = 1;
        float b_ = 1;
        float a_ = 1;
    };
}
