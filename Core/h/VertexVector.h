#pragma once

#include <vector>
#include <initializer_list>

#include <Core_api.h>
#include <Core/h/Vertex.h>

namespace easy::core {
    class CORE_EXPORT VertexVector {
    public:
        using iterator = std::vector<Vertex>::iterator;
        using const_iterator = std::vector<Vertex>::const_iterator;

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

        iterator begin() { return data_.begin(); }
        iterator end() { return data_.end(); }

        const_iterator begin() const { return data_.begin(); }
        const_iterator end() const { return data_.end(); }


    private:
        std::vector<Vertex> data_;
    };
}
