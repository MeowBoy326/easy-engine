#include <Core/h/BufferData.h>

namespace easy::graphics::core {

    BufferData::BufferData(VertexVector& data, GLuint type) : data_(data), type_(type)
    {
        cache_data_size_ = data_.Size();
		glGenBuffers(1, &id_);
		glBindBuffer(type, id_);
		glBufferData(type, data_.SizeOf(), data_.GetRaw(), GL_DYNAMIC_DRAW);
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

    const VertexVector& BufferData::GetData() const
    {
        return data_;
    }

    VertexVector& BufferData::GetData()
    {
        return data_;
    }

    void BufferData::Update()
    {
        Bind();
        
        if (data_.Size() > cache_data_size_) {
            glBufferData(type_, data_.SizeOf(), data_.GetRaw(), GL_DYNAMIC_DRAW);
            cache_data_size_ = data_.Size();
        }
        else {
            glBufferSubData(type_, 0, data_.SizeOf(), data_.GetRaw());
        }
    }
}
