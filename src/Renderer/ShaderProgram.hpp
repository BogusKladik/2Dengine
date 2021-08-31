#pragma once

#include <glad/glad.h>
#include <string>

namespace Renderer {
    class ShaderProgram
    {
    private:
        bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);

        bool m_isCompiled = false;
        GLuint m_ID = 0;
    public:
        ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
        ~ShaderProgram();
        bool isCompiled() const { return m_isCompiled; }
        void use() const;

        ShaderProgram() = delete;
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;
        ShaderProgram& operator=(ShaderProgram&& shaderProgram);
        ShaderProgram(ShaderProgram&& shaderProgram);
    };
}