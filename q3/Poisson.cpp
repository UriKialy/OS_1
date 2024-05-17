#include "Poisson.hpp"
long double Poisson(long double lambda, int k) {
    long double result = (std::exp(-lambda)) * (std::pow(lambda, k) / std::tgamma(k+1));
    return result;
}