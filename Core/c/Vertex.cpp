#include <Core/h/Vertex.h>

namespace easy::graphics::core {

    Vertex::Vertex(float x, float y, float z):
        x_(x),
        y_(y),
        z_(z)
    {
    }

    Vertex::Vertex(float x, float y, float z, const core::Color& color) :
        x_(x),
        y_(y),
        z_(z),
        color_(color)
    {
    }

    VertexUnitType* Vertex::GetRaw()
    {
        return (VertexUnitType*)this;
    }

    float& Vertex::X()
    {
        return x_;
    }

    float& Vertex::Y()
    {
        return y_;
    }

    float& Vertex::Z()
    {
        return z_;
    }

    Color& Vertex::Color()
    {
        return color_;
    }

}