#include "q5.hpp"

int main(int argc, char* argv[]){
    int input1, input2;
    std::cout << "Enter seed: ";
    std::cin >> input1;
    std::cout << "Enter n: ";
    std::cin >> input2;

    maxSubArray(input1,input2);

return 0;
}