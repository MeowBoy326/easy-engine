#include <Core/h/BufferData.h>

namespace easy::graphics::core {

    BufferData::BufferData(GLuint type) : type_(type)
    {
		glGenBuffers(1, &id_);
		glBindBuffer(type, id_);
    }

    BufferData::~BufferData()
    {
        glDeleteBuffers(1, &id_);
    }

    void BufferData::Bind() const
    {
        glBindBuffer(type_, id_);
    }

    void BufferData::UnBind() const
    {
        glBindBuffer(type_, 0);
    }

    void BufferData::Update(const VertexVector& data)
    {
        Bind();
        
        if (data.Size() > cache_data_size_) {
            glBufferData(type_, data.SizeOf(), data.GetRaw(), GL_DYNAMIC_DRAW);
            cache_data_size_ = data.Size();
        }
        else {
            glBufferSubData(type_, 0, data.SizeOf(), data.GetRaw());
        }
    }
}
