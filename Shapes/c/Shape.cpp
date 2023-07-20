#include <Shapes/h/Shape.h>

namespace easy::graphics::shapes {

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
