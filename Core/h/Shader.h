#pragma once

#include <filesystem>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Core_api.h>
#include <Core/h/DefaultShaders.h>

namespace easy::graphics::core {
    class CORE_EXPORT Shader {
    public:
        Shader() = default;
        Shader(const Shader& other);
        Shader(Shader&& other);

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
        GLuint id_ = 0;
        GLuint type_ = 0;
        char* data_ = nullptr;
        size_t data_size_ = 0;
        bool was_allocated_ = false;

        GLuint Compile(GLuint type, char*& data);
        std::string LogInfo(GLuint id, GLuint type);
        std::pair<char*, size_t> LoadFromFile(const std::filesystem::path& path);
    };

    struct DefaultShaders {
    public:
        static Shader Vertex()
        {
            return Shader(GL_VERTEX_SHADER, DEFAULT_VERTEX_SHADER_SOURCE);
        }

        static Shader Fragment()
        {
            return Shader(GL_FRAGMENT_SHADER, DEFAULT_FRAGMENT_SHADER_SOURCE);
        }
    private:
        DefaultShaders() = default;
    };
}
