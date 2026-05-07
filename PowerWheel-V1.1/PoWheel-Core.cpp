#include "PoWheel-API.hpp"
#include <fstream>
#include <iostream>
Engine& Engine::instance() {
    static Engine instance;
    return instance;
}
bool Engine::init(const std::string& configPath) {
    std::ifstream config(configPath);

    if (!config.is_open()) {
     std::cout << "Configuration file wasn't found in the Engine directory ";
     return false;
    }
 std::string line;
while (std::getline(config, line)) {
    if (line.find("PWL-MATH=true") !=std::string::npos) {
    moduleStatus["PWL-MATH"] = true;
    }
    if (line.find("PWL-IN/OUT=true") !=std::string::npos) {
    moduleStatus["PWL-IN/OUT"] = true;
    }
}
config.close();
return true;
}
bool Engine::isModuleEnabled(const std::string& name) const {
    auto it = moduleStatus.find(name);
    if (it != moduleStatus.end()) {
     return it->second;
    }
    return false;
}
