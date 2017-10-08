#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

void init(int size)
{
    dp.resize(size);
}

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