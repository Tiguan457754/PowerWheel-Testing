#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>
int main() {
    std::ifstream config("config.cfg");
    if (!config.is_open()) {
        std::cout << "Plik konfiguracji nie został odnaleziony";
        return 1;
    }
    bool inout_active = false;
    bool math_active = false;
    std::string line;
    while (std::getline(config, line)) {
    if (line.find("PWL-IN/OUT=true") != std::string::npos) {
    inout_active = true;
    }
    if (line.find("PWL-MATH=true") != std::string::npos) {
    math_active = true;
    }
    }
    config.close();
    std::cout << "--- Inicjalizacja PowerWheel ---" << std::endl;
if (inout_active) std::cout << "[CORE] Modul Wejść/Wyjść: AKTYWNY" << std::endl;
if (math_active)  std::cout << "[CORE] Modul Matematyczny:   AKTYWNY" << std::endl;
}