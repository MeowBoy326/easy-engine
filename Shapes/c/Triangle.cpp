#include <Shapes/h/Triangle.h>

namespace easy::shapes {

    Triangle::Triangle() : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push({});
        vertices_.Push({});
        vertices_.Push({});
        Update();
    }

    Triangle::Triangle(const core::Vertex& p1, const core::Vertex& p2, const core::Vertex& p3) : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push(p1);
        vertices_.Push(p2);
        vertices_.Push(p3);
        Update();
    }

    const core::Vertex& Triangle::P1() const 
    {
        return vertices_.At(0);
    }

    const core::Vertex& Triangle::P2() const 
    {
        return vertices_.At(1);
    }

    const core::Vertex& Triangle::P3() const 
    {
        return vertices_.At(2);
    }

    void Triangle::P1(const core::Vertex& vertex)
    {
        vertices_.At(0) = vertex;
        Update();
    }

    void Triangle::P1(const core::Position& position)
    {
        vertices_.At(0).Position() = position;
        Update();
    }

    void Triangle::P2(const core::Vertex& vertex)
    {
        vertices_.At(1) = vertex;
        Update();
    }

    void Triangle::P2(const core::Position& position)
    {
        vertices_.At(1).Position() = position;
        Update();
    }

    void Triangle::P3(const core::Vertex& vertex)
    {
        vertices_.At(2) = vertex;
        Update();
    }

    void Triangle::P3(const core::Position& position)
    {
        vertices_.At(2).Position() = position;
        Update();
    }

    void Triangle::Draw()
    {
        BaseDraw(vertices_, GL_TRIANGLES);
    }
}
