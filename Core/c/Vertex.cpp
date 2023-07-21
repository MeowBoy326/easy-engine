#include <Core/h/Vertex.h>

namespace easy::core {

    Vertex::Vertex(const core::Position& position) : position_(position)
    {
    }

    Vertex::Vertex(const core::Position& position, const core::Color& color) :
        position_(position),
        color_(color)
    {
    }

    VertexUnitType* Vertex::GetRaw()
    {
        return (VertexUnitType*)this;
    }

    core::Position& Vertex::Position()
    {
        return position_;
    }

    const core::Position& Vertex::Position() const
    {
        return position_;
    }

    core::Color& Vertex::Color()
    {
        return color_;
    }

    const core::Color& Vertex::Color() const
    {
        return color_;
    }



}