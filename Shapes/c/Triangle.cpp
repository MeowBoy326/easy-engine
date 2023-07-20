#include <Shapes/h/Triangle.h>

namespace easy::graphics::shapes {

    Triangle::Triangle() : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push({});
        vertices_.Push({});
        vertices_.Push({});
    }

    Triangle::Triangle(const core::Vertex& p1, const core::Vertex& p2, const core::Vertex& p3) : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push(p1);
        vertices_.Push(p2);
        vertices_.Push(p3);
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

    core::Vertex& Triangle::P1()
    {
        return vertices_.At(0);
    }

    core::Vertex& Triangle::P2()
    {
        return vertices_.At(1);
    }

    core::Vertex& Triangle::P3()
    {
        return vertices_.At(2);
    }

    void Triangle::Draw()
    {
        BaseDraw(vertices_, GL_TRIANGLES);
    }
}
