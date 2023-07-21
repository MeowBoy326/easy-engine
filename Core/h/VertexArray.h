#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/BufferData.h>

namespace easy::core {
    class CORE_EXPORT VertexArray {
    public:
        VertexArray();
        VertexArray(const VertexArray&) = default;
        VertexArray(VertexArray&&) = default;

        ~VertexArray();

        void AddBuffer(const BufferData& vb);
        void Bind() const;
        void UnBind() const;

    private:
        GLuint id_   = 0;
    };
}
