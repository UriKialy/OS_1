#include <iostream>
void recursiveFunction();
int main() {
    recursiveFunction();
    return 0;
}

void recursiveFunction() {
    recursiveFunction();
}
