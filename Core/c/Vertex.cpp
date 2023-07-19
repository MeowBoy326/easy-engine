#include <Core/h/Vertex.h>

namespace easy::graphics::core {

    Vertex::Vertex(float x, float y, float z):
        x_(x),
        y_(y),
        z_(z)
    {
    }

    Vertex::Vertex(float x, float y, float z, float r, float g, float b, float a) :
        x_(x),
        y_(y),
        z_(z),
        r_(r),
        g_(g),
        b_(b),
        a_(a)
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