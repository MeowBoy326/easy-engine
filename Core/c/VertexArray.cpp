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
        int elements = Vertex::POSITION_ELEMENTS + Vertex::COLOR_ELEMENTS;

        // position attribute
        glVertexAttribPointer(0, Vertex::POSITION_ELEMENTS, GL_FLOAT, GL_FALSE,
            elements * sizeof(float), NULL);
        glEnableVertexAttribArray(0);

        // color attribute
        glVertexAttribPointer(1, Vertex::COLOR_ELEMENTS, GL_FLOAT, GL_FALSE,
            elements * sizeof(float), (void*)(Vertex::POSITION_ELEMENTS * sizeof(float)));
        glEnableVertexAttribArray(1);
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
