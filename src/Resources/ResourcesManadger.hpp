#pragma once

#include <string>
#include <memory>
#include <map>

namespace Renderer{
    class ShaderProgram;    
}


class ResourcesManadger{
private:
    std::string getFileString(const std::string& relativeFilePath) const;

    typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramMap;
    ShaderProgramMap m_shaderPrograms;

    std::string m_path;
public:
    ResourcesManadger(const std::string& executablePath);
    ~ResourcesManadger() = default;

    ResourcesManadger(const ResourcesManadger&) = delete;
    ResourcesManadger& operator=(const ResourcesManadger&) = delete;
    ResourcesManadger& operator=(ResourcesManadger&&) = delete;
    ResourcesManadger(ResourcesManadger&&) = delete;

    std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);
};