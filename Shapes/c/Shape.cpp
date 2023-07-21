#include <Shapes/h/Shape.h>

namespace easy::shapes {

    Shape::Shape(GLuint buffer_type) : RenderTarget(buffer_type), component::Transform(vertices_)
    {
    }

    Shape::Shape(GLuint buffer_type, const core::ShaderProgram& shader_program) :
        RenderTarget(buffer_type, shader_program),
        Transform(vertices_)
    {
    }

    void Shape::SetFillColor(const core::Color& color)
    {
        fill_color_ = color;

        for (auto& vertex : vertices_) {
            vertex.Color() = color;
        }
    }

    const core::Color& Shape::GetFillColor() const
    {
        return fill_color_;
    }
}
