#include <Core/h/RenderTarget.h>

namespace easy::graphics::core {
    RenderTarget::RenderTarget(GLuint buffer_type) : VAO(), VBO(buffer_type)
    {
        std::vector<easy::graphics::core::Shader> shaders;
        shaders.push_back(DefaultShaders::Vertex());
        shaders.push_back(DefaultShaders::Fragment());
        shader_program = ShaderProgram(shaders);
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

    void RenderTarget::Draw()
    {
    }

    void RenderTarget::Draw(const VertexVector& vertices, GLuint primitive_type)
    {
        DrawImpl(vertices, primitive_type);
    }

    void RenderTarget::DrawImpl(const VertexVector& vertices, GLuint primitive_type)
    {
        BaseDraw(vertices, primitive_type);
    }

    void RenderTarget::BaseDraw(const VertexVector& vertices, GLuint primitive_type)
    {
        VAO.Bind();
        VBO.Update(vertices);
        shader_program.Run();
        glDrawArrays(primitive_type, 0, (GLsizei)vertices.Size());
    }
}
