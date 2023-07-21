#include <stdexcept>
#include <cstring>

#include <boost/iostreams/device/mapped_file.hpp>

#include <Core/h/Shader.h>

namespace easy::core {

    Shader::Shader(GLuint type, const std::filesystem::path& path)
    {
        Load(type, path);
    }

    Shader::Shader(GLuint type, const char*& data)
    {
        Load(type, data);
    }

    Shader::Shader(GLuint type, const std::string& data)
    {
        Load(type, data);
    }

    Shader::Shader(const Shader& other)
    {
        was_allocated_ = other.was_allocated_;
        if (was_allocated_) {
            data_ = new char[other.data_size_];
            std::memcpy(data_, other.data_, other.data_size_);
            data_size_ = other.data_size_;
        }

        Load(other.type_, (const char*&)other.data_);
    }

    Shader::Shader(Shader&& other)
    {
        id_ = other.id_;
        other.id_ = 0;
        type_ = other.type_;
        other.type_ = 0;
        was_allocated_ = other.was_allocated_;
        other.was_allocated_ = false;
        data_ = other.data_;
        other.data_ = nullptr;
        data_size_ = other.data_size_;
        other.data_size_ = 0;
    }

    Shader::~Shader()
    {
        Clean();
    }

    void Shader::Clean()
    {
        if (type_ != 0)
            glDeleteShader(id_);

        if (was_allocated_ && data_ != nullptr)
            delete[] data_;

        was_allocated_ = false;
        data_ = nullptr;
        data_size_ = 0;
        type_ = 0;
    }


    GLuint Shader::GetId() const
    {
        return id_;
    }

    GLuint Shader::GetType() const
    {
        return type_;
    }

    void Shader::Load(GLuint type, const std::filesystem::path& path)
    {
        Clean();
        type_ = type;
        auto pair = LoadFromFile(path);
        data_ = pair.first;
        data_size_ = pair.second;
        was_allocated_ = true;
    }

    void Shader::Load(GLuint type, const char*& data)
    {
        Clean();
        type_ = type;
        data_ = (char*)data;
        data_size_ = strlen(data);
        id_ = Compile(type_, data_);
    }

    void Shader::Load(GLuint type, const std::string& data)
    {
        Clean();
        type_ = type;
        data_ = (char*)data.c_str();
        data_size_ = data.size();
        id_ = Compile(type_, data_);
    }

    GLuint Shader::Compile(GLuint type, char*& data)
    {
        GLuint id = glCreateShader(type);
        glShaderSource(id, 1, &data, NULL);
        glCompileShader(id);

        std::string log = LogInfo(id, type);
        if (not log.empty()) throw std::runtime_error(log);

        return id;
    }

    std::string Shader::LogInfo(GLuint id, GLuint type)
    {
        GLint status;
        std::string log;
        GLsizei info_lenght = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);

        if (status == GL_FALSE) {
            glGetShaderiv(id, type, &info_lenght);
            log.resize(info_lenght);
            glGetShaderInfoLog(id, info_lenght, NULL, &log.front());
        }

        return log;
    }

    std::pair<char*, size_t> Shader::LoadFromFile(const std::filesystem::path& path)
    {
        boost::iostreams::mapped_file_source file(path.string());
        char* file_data;

        if (!file.is_open()) {
            std::string error = "Could not open Shader file: ";
            error += path.string();
            throw std::runtime_error(error);
        }

        file_data = new char[file.size()];
        std::memcpy(file_data, file.data(), file.size());
        return { file_data, file.size() };
    }

}

