#include "q1.hpp"
int main() {
    recursiveFunction();
    crashFunction();
    invalidMemoryAccess();
    return 0;
}
void recursiveFunction() {
    recursiveFunction();
}
void crashFunction() {
    int numerator = 10;
    int denominator = 0;
    int result = numerator / denominator;
    if(result == 0) {
        std::cout << "Crash function: Division by zero" << std::endl;
    }
}
void invalidMemoryAccess() {
    int* ptr = nullptr;
    *ptr = 10;
}
