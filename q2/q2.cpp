#include "q2.hpp"

using namespace std;
// Function to calculate the Poisson distribution
long double Poisson( long double lambda,int k) {
    long double result = (std::exp(-lambda)) * (pow(lambda, k) / tgamma(k + 1));
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3)  { // 2 numbers and the name of the program
        cout << "Error there was " <<argc<<" insted of 2 args"<< std::endl;
        return 1;
    }

    int k = std::atoi(argv[2]); // Convert the string at argv[2] to an integer and assign it to k
    long double lambda = std::atof(argv[1]); // Convert the string at argv[1] to a floating-point number and assign it to lambda

    long  double poissonResult = Poisson(lambda,k);
    cout << "Poisson result: " << poissonResult << std::endl;

    return 0;
}
 
