#include <iostream>
void invalidMemoryAccess();

int main() {
    invalidMemoryAccess();
    return 0;
}
void invalidMemoryAccess() {
    int* ptr = nullptr;
    *ptr = 10;
}