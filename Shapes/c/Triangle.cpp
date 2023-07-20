#include <Shapes/h/Triangle.h>

namespace easy::graphics::shapes {

    Triangle::Triangle() : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push({});
        vertices_.Push({});
        vertices_.Push({});
        RecalculateCenter();
    }

    Triangle::Triangle(const core::Vertex& p1, const core::Vertex& p2, const core::Vertex& p3) : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push(p1);
        vertices_.Push(p2);
        vertices_.Push(p3);
        RecalculateCenter();
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
        RecalculateCenter();
    }

    void Triangle::P1(const core::Position& position)
    {
        vertices_.At(0).Position() = position;
        RecalculateCenter();
    }

    void Triangle::P2(const core::Vertex& vertex)
    {
        vertices_.At(1) = vertex;
        RecalculateCenter();
    }

    void Triangle::P2(const core::Position& position)
    {
        vertices_.At(1).Position() = position;
        RecalculateCenter();
    }

    void Triangle::P3(const core::Vertex& vertex)
    {
        vertices_.At(2) = vertex;
        RecalculateCenter();
    }

    void Triangle::P3(const core::Position& position)
    {
        vertices_.At(2).Position() = position;
        RecalculateCenter();
    }

    void Triangle::Draw()
    {
        BaseDraw(vertices_, GL_TRIANGLES);
    }

    void Triangle::Position(const core::Position& position)
    {
        auto distance = position - center_;
        for (auto& vertex : vertices_)
            vertex.Position() = vertex.Position() + distance;
        RecalculateCenter();
    }

    const core::Position& Triangle::Position() const
    {
        return center_;
    }

    static float CenterCoordinate(float a, float b, float c)
    {
        return (a + b + c) / 3.f;
    }

    void Triangle::RecalculateCenter()
    {
        center_.x = CenterCoordinate(vertices_.At(0).Position().x, vertices_.At(1).Position().x, vertices_.At(2).Position().x);
        center_.y = CenterCoordinate(vertices_.At(0).Position().y, vertices_.At(1).Position().y, vertices_.At(2).Position().y);
    }
}
