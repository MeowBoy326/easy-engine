#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/VertexArray.h>
#include <Core/h/BufferData.h>
#include <Core/h/ShaderProgram.h>


// Todo: Recibir parametro para los vertices y tipo de elemento a dibujar en buffer data 

namespace easy::graphics::core {
    class CORE_EXPORT RenderTarget {
    public:
        RenderTarget(GLuint buffer_type);
        RenderTarget(GLuint buffer_type, const ShaderProgram& shader_program);

        void SetShaderProgram(const ShaderProgram& shader_program);
        virtual void Draw(const VertexVector& vertices, GLuint primitive_type);
        
    protected:
        VertexArray VAO;
        BufferData  VBO;
        ShaderProgram shader_program;

        void BaseDraw();
    };
}
