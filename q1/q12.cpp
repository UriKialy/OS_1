#include <iostream>
void crashFunction();
int main() {
    crashFunction();
    return 0;
}
void crashFunction() {
    int numerator = 10;
    int denominator = 0;
    int result = numerator / denominator;
    if(result == 0) {
        std::cout << "Crash function: Division by zero" << std::endl;
    }
}