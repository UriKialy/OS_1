#include "q5.hpp"
// algorithms O(n^3)
void maxSubArray(int seed, int n)
{
    int arr[n];
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100) - 25;
    }
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += arr[k];
            }
            best = best > sum ? best : sum;
        }
    }
    cout << best << "\n";
}