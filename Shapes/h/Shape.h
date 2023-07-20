#pragma once

#include <Shapes_api.h>

#include <Core/h/RenderTarget.h>

namespace easy::graphics::shapes {

    class SHAPES_EXPORT Shape : protected core::RenderTarget {
    public:
        using RenderTarget::RenderTarget;

        void SetFillColor(const core::Color& color);
        const core::Color& GetFillColor() const;

    protected:
        core::VertexVector vertices_;
        core::Color fill_color_;
    };
}
