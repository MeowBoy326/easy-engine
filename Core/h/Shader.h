#pragma once

#include <filesystem>
#include <functional>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>


namespace easy::graphics::core {
    class CORE_EXPORT Shader {
    public:
        Shader() = default;
        Shader(Shader&&) = default;

        explicit Shader(GLuint type, const std::filesystem::path& path);
        explicit Shader(GLuint type, const char*& data);
        explicit Shader(GLuint type, const std::string& data);

        ~Shader();

        GLuint GetId() const;
        GLuint GetType() const;

        void Load(GLuint type, const std::filesystem::path& path);
        void Load(GLuint type, const char*& data);
        void Load(GLuint type, const std::string& data);

        void Clean();

    private:
        GLuint id_ = -1;
        GLuint type_ = -1;
        char* data_ = nullptr;
        bool was_allocated_ = false;

        GLuint Compile(GLuint type, char*& data);
        std::string LogInfo(GLuint id, GLuint type);
        char* LoadFromFile(const std::filesystem::path& path);
    };
}
