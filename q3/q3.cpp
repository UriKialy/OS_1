#include "Poisson.hpp"
using namespace std;
int main() {
    double array[5][2]= {{2,1}, {2, 10}, {2,2}, {3,3}, {100, 3}};
    for (int i = 0; i < 5; i++) {
        double lambda = array[i][0];
        double k = array[i][1];
        long double result = Poisson(k,lambda);
        std::cout << "Poisson result for pair (" << lambda << ", " << k << "): " << result << std::endl;
    }

    return 0;
}


