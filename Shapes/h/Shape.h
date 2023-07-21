#pragma once

#include <Shapes_api.h>

#include <Core/h/RenderTarget.h>
#include <Components/h/Transform.h>

namespace easy::shapes {

    class SHAPES_EXPORT Shape : protected core::RenderTarget, public component::Transform {
    public:
        using RenderTarget::RenderTarget;

        Shape(const Shape&) = default;
        Shape(Shape&&) = default;
        Shape(GLuint buffer_type);
        Shape(GLuint buffer_type, const core::ShaderProgram& shader_program);

        Shape& operator=(const Shape&) = default;
        Shape& operator=(Shape&&) = default;


        void SetFillColor(const core::Color& color);
        const core::Color& GetFillColor() const;

    protected:
        core::VertexVector vertices_;
        core::Color fill_color_;
    };
}
