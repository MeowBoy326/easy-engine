#include <Core/h/VertexArray.h>

namespace easy::graphics::core {
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &id_);
        glBindVertexArray(id_);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &id_);
    }

    void VertexArray::AddBuffer(const BufferData& vb)
    {
        vb.Bind();
        auto data = vb.GetData();
        int elements = sizeof(Vertex) / sizeof(float);
        glVertexAttribPointer(0, elements, GL_FLOAT, GL_FALSE, elements * sizeof(float), NULL);
        glEnableVertexAttribArray(0);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id_);
    }

    void VertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }
}
