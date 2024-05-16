#include "q2.hpp"

using namespace std;
// Function to calculate the Poisson distribution
long double Poisson(int k, long double lambda) {
    long double result = (std::exp(-lambda)) * (pow(lambda, k) / tgamma(k + 1));
    return result;
}

int main(int argc, char* argv[]) {
    if (argc!=2) {
        cout << "Error" << std::endl;
        return 1;
    }

    int k = std::atoi(argv[1]); // Convert the string at argv[1] to an integer and assign it to k
    long double lambda = std::atof(argv[2]); // Convert the string at argv[2] to a floating-point number and assign it to lambda

    long  double poissonResult = Poisson(k, lambda);
    cout << "Poisson result: " << poissonResult << std::endl;

    return 0;
}
 
