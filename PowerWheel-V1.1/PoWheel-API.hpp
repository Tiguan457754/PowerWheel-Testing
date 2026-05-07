#pragma once
#include <string>
#include <unordered_map>
class Engine {
    public:
    static Engine& instance();
    bool init(const std::string& configPath);
    bool isModuleEnabled(const std::string& name) const;
    private:
    Engine() = default;
    std::unordered_map<std::string, bool> moduleStatus;
};