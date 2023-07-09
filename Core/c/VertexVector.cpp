#include <Core/h/VertexVector.h>

namespace easy::graphics::core {

    VertexVector::VertexVector(std::initializer_list<Vertex>&& vertices)
    {
        data_.reserve(vertices.size());
        for (auto& vertex : vertices) {
            data_.push_back(vertex);
        }
    }


    void VertexVector::Push(const Vertex& vertex)
    {
        data_.push_back(vertex);
    }

    void VertexVector::Clear()
    {
        data_.clear();
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