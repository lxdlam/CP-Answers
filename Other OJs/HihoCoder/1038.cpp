#include <iostream>
#include <algorithm>
#include <vector>

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, size;
    int cost, value;
    vector<int> costs, values;
    cin >> T >> size;
    while (T--)
    {
        cin >> cost >> value;
        costs.push_back(cost);
        values.push_back(value);
    }
    for (int i = 0; i < costs.size(); i++)
        ZeroOnePack(costs[i], values[i], size);
    cout << dp[size] << endl;
    return 0;
}