#pragma once

#include <Core_api.h>

#include <GLFW/glfw3.h>

namespace easy::graphics::core {
    typedef float VertexUnitType ;

    class CORE_EXPORT Vertex {
    public:
        Vertex() = default;
        Vertex(const Vertex &) = default;
        Vertex(Vertex&&) = default;
        Vertex(float x, float y, float z);

        VertexUnitType* GetRaw();
        float& GetX();
        float& GetY();
        float& GetZ();

    private:
        float x_ = 0;
        float y_ = 0;
        float z_ = 0;
    };
}
