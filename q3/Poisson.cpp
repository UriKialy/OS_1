#include "Poisson.hpp"
long double Poisson(int k, long double lambda) {
    long double result = (std::exp(-lambda)) * (std::pow(lambda, k) / std::tgamma(k+1));
    return result;
}