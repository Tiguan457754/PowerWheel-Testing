#include "PoWheel-API.hpp"
#include <iostream>
int main() {
    if (!Engine::instance().init("config.cfg")) {
    std::cout << "engine initialization failed. Exiting." << std::endl;
    return 1;
    }
    std::cout << "---PowerWheel Shell---" << std::endl;
    if (Engine::instance().isModuleEnabled("PWL-MATH")) 
    { std::cout << "[PWL Shell] Math Module: Enabled" << std::endl; }
    if (Engine::instance().isModuleEnabled("PWL-IN/OUT")) 
    { std::cout << "[PWL Shell] IO Module: Enabled" << std::endl; }
    return 0;
}
