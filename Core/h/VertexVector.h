#pragma once

#include <vector>
#include <initializer_list>

#include <Core_api.h>
#include <Core/h/Vertex.h>

namespace easy::graphics::core {
    class CORE_EXPORT VertexVector {
    public:
        VertexVector() = default;
        VertexVector(const VertexVector&) = default;
        VertexVector(VertexVector&&) = default;
        VertexVector(std::initializer_list<Vertex>&& vertices);


        Vertex& At(size_t index);
        const Vertex& At(size_t index) const;

        void Push(const Vertex& vertex);
        void Clear();

        size_t SizeOf() const;
        size_t Size() const;

        Vertex* GetRaw();
        const Vertex* GetRaw() const;

    private:
        std::vector<Vertex> data_;
    };
}
