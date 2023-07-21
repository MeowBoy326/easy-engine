#pragma once

#include <vector>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/Shader.h>

namespace easy::core {
    class CORE_EXPORT ShaderProgram {
    public:
        ShaderProgram() = default;
        ShaderProgram(const std::vector<Shader>& shaders);
        ~ShaderProgram();

        void Load(const std::vector<Shader>& shaders);
        void Clean();
        void Run();

    private:
        GLuint id_ = 0;
    };
}
