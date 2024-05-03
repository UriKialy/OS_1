#include "q3.hpp"
long double Poisson(int k, long double lambda) {
    long double result = (std::exps(-lambda)) * (std::pow(lambda, k) / std::tgamma(k+1));
    return result;
}