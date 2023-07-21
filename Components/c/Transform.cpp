#include <Components/h/Transform.h>

namespace easy::component {
    Transform::Transform(core::VertexVector& vertices) : vertices_(vertices)
    {
    }

    core::Position Transform::CalculateCenter(const core::VertexVector& vertices)
    {
        core::Position result(0, 0);

        if (vertices.Size() == 1) return vertices.At(0).Position();

        for (const auto& vertex : vertices) {
            result.x += vertex.Position().x;
            result.y += vertex.Position().y;
            result.z += vertex.Position().z;
        }

        result.x = result.x / (float)vertices.Size();
        result.y = result.y / (float)vertices.Size();
        result.z = result.z / (float)vertices.Size();

        return result;
    }

    void Transform::Position(const core::Position& position)
    {
        auto distance = position - position_;
        for (auto& vertex : vertices_)
            vertex.Position() = vertex.Position() + distance;
        Update();
    }

    const core::Position& Transform::Position() const
    {
        return position_;
    }

    void Transform::Update()
    {
        position_ = CalculateCenter(vertices_);
    }
}
