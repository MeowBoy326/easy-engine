#pragma once

#include <Shapes_api.h>

#include <Core/h/RenderTarget.h>

namespace easy::graphics::shapes {

    class SHAPES_EXPORT Shape : protected core::RenderTarget {
    public:
        using RenderTarget::RenderTarget;
    protected:
        core::VertexVector vertices_;
    };
}
