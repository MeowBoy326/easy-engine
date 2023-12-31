#pragma once

#include <Components_api.h>
#include <Core/h/Position.h>
#include <Core/h/VertexVector.h>

namespace easy::component {
    class COMPONENTS_EXPORT Transform {
    public:
        Transform(core::VertexVector& vertices);

        void Position(const core::Position& position);
        const core::Position& Position() const;

        float Angle() const;
        void  Rotate(float angle);

        static core::Position CalculateCenter(const core::VertexVector& vertices);

    protected:
        void Update();

    private:
        float angle_ = 0.f; //< degress
        core::Position position_;
        core::VertexVector& vertices_;
    };
}
