#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/VertexArray.h>
#include <Core/h/BufferData.h>
#include <Core/h/ShaderProgram.h>

namespace easy::graphics::core {
    class CORE_EXPORT RenderTarget {
    public:
        RenderTarget(GLuint buffer_type);
        RenderTarget(GLuint buffer_type, const ShaderProgram& shader_program);

        void SetShaderProgram(const ShaderProgram& shader_program);
        void Draw(const VertexVector& vertices, GLuint primitive_type);
        virtual void Draw();


    protected:
        void BaseDraw(const VertexVector& vertices, GLuint primitive_type);
        virtual void DrawImpl(const VertexVector& vertices, GLuint primitive_type);

    private:
        VertexArray VAO;
        BufferData  VBO;
        ShaderProgram shader_program;
    };
}