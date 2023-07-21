#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/VertexVector.h>

namespace easy::core {
    class CORE_EXPORT BufferData {
    public:
        BufferData(GLuint type);
        BufferData(const BufferData&) = default;
        BufferData(BufferData&&) = default;
        ~BufferData();

        void Bind() const;
        void UnBind() const;

        const VertexVector& GetData() const;
        VertexVector& GetData();

        void Update(const VertexVector& data);

    private:
        GLuint id_   = 0;
        GLuint type_ = 0;
        size_t cache_data_size_ = 0;
    };
}
