#include <Core/h/RenderTarget.h>

namespace easy::graphics::core {
    RenderTarget::RenderTarget(GLuint buffer_type) : VAO(), VBO(buffer_type)
    {
        VAO.AddBuffer(VBO);
    }

    RenderTarget::RenderTarget(GLuint buffer_type, const ShaderProgram& shader_program) :
        VAO(),
        VBO(buffer_type),
        shader_program(shader_program)
    {
        VAO.AddBuffer(VBO);
    }

    void RenderTarget::SetShaderProgram(const ShaderProgram& shader_program)
    {
        this->shader_program = shader_program;
    }

    void RenderTarget::Draw(const VertexVector& vertices, GLuint primitive_type)
    {
        VAO.Bind();
        VBO.Update(vertices);
        shader_program.Run();
        glDrawArrays(primitive_type, 0, vertices.Size());
    }
}
