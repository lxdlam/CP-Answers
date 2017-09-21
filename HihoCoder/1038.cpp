#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 10;

int dp[MAX] = {0};

int ZeroOnePack(vector<int> &costs, vector<int> &values, int size)
{
    return 0;
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
    cout << ZeroOnePack(costs, values, size) << endl;
    return 0;
}