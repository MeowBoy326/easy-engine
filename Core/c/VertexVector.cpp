#include <Core/h/VertexVector.h>

namespace easy::graphics::core {

    VertexVector::VertexVector(std::initializer_list<Vertex>&& vertices)
    {
        data_.reserve(vertices.size());
        for (auto& vertex : vertices) {
            data_.push_back(vertex);
        }
    }

    Vertex& VertexVector::At(size_t index)
    {
        return data_[index];
    }

    void VertexVector::Push(const Vertex& vertex)
    {
        data_.push_back(vertex);
    }

    void VertexVector::Clear()
    {
        data_.clear();
    }

    size_t VertexVector::SizeOf() const
    {
        return data_.size() * sizeof(Vertex);
    }

    size_t VertexVector::Size() const
    {
        return data_.size();
    }

    Vertex* VertexVector::GetRaw()
    {
        return data_.data();
    }

}