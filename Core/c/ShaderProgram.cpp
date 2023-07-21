#include <stdexcept>

#include <Core/h/ShaderProgram.h>

namespace easy::core {

    ShaderProgram::ShaderProgram(const std::vector<Shader>& shaders)
    {
        Load(shaders);
    }

    ShaderProgram::~ShaderProgram()
    {
    }

    void ShaderProgram::Clean()
    {
        if (id_ != 0)
            glDeleteProgram(id_);
        id_ = 0;
    }

    void ShaderProgram::Load(const std::vector<Shader>& shaders)
    {
        Clean();
        id_ = glCreateProgram();

        for (auto& shader : shaders)
            glAttachShader(id_, shader.GetId());

        glLinkProgram(id_);
    }

    void ShaderProgram::Run()
    {
        if (id_ == 0) throw std::runtime_error("ShaderProgram was not initialized");
        glUseProgram(id_);
    }

}

