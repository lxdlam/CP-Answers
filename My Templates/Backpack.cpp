#include <algorithm>

using namespace std;

const int SIZE = 1e6 + 10;

int dp[SIZE] = {0};

//call it N times, n stands for the number of items
void ZeroOnePack(int cost, int value, int size)
{
    for (int i = size; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + value);
}

void CompletePack(int cost, int value, int size)
{
    for (int i = cost; i <= size; i++)
        dp[i] = max(dp[i], dp[i - cost] + value);
}