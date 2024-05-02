#include <iostream>

int main(int argc, char* argv[]) {
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
}
void invalidMemoryAccess() {
    int* ptr = nullptr;
    *ptr = 10;
}
