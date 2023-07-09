#include <Core/h/Vertex.h>

namespace easy::graphics::core {

    Vertex::Vertex(float x, float y, float z) :
        x_(x),
        y_(y),
        z_(z)
    {
    }

    VertexUnitType* Vertex::GetRaw()
    {
        return (VertexUnitType*)this;
    }

    float& Vertex::GetX()
    {
        return x_;
    }

    float& Vertex::GetY()
    {
        return y_;
    }

    float& Vertex::GetZ()
    {
        return z_;
    }

}