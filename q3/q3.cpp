#include "q3.hpp"
using namespace std;
int main() {
    double array[5][2]= {{2,1}, {2, 10}, {2,2}, {3,3}, {100, 3}};
    for (int i = 0; i < 5; i++) {
        double x = array[i][0];
        double y = array[i][1];
        long double result = Poisson(x, y);
        std::cout << "Poisson result for pair (" << x << ", " << y << "): " << result << std::endl;
    }

    return 0;
}

long double Poisson(int k, long double lambda) {
    long double result = (std::exp(-lambda) * std::pow(lambda, k)) / std::tgamma(k + 1);
    return result;
}
