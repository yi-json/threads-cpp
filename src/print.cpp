#include <iostream>
#include <thread>

void f1(char symbol) {
    for(int i = 0; i < 200; ++i) {
        std::cout << symbol;
    }
}

void f2() {
    for(int i = 0; i < 200; ++i) {
        std::cout << "-";
    }
}

int main() {
    std::thread worker1(f1, 'o');
    std::thread worker2(f2);
    
    // Wait for both threads to finish
    worker1.join();
    worker2.join();

    std::cout << "\n[Done]" << std::endl;

}