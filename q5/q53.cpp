#include "q5.hpp"
// algorithms O(n)
void maxSubArray(int seed, int n)
{
    int arr[n];
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100) - 25;
    }
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum = max(arr[k], sum + arr[k]);
        best = best > sum ? best : sum;
    }
    cout << best << "\n";
}