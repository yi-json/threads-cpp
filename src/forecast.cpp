#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> forecastMap) {
    while (true) {
        for (auto& [k, v] : forecastMap) {
            v++;
            std::cout << k << " - " << v << std::endl;
        }
        std::cout << "\n";
        std::this_thread::sleep_for(2000ms);
    }
}

int main() {
    std::map<std::string, int> forecastMap = {
        {"New York", 15},
        {"Mumbai", 20},
        {"Berlin", 18},
    };

    std::thread bgWorker(RefreshForecast, forecastMap);
    bgWorker.detach();

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "[Main finished]\n";
    
}