#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<long long>> matrix;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    matrix m1, m2, res;
    int n, p, m;
    long long t;
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++)
    {
        vector<long long> temp;
        m1.emplace_back(std::move(temp));
        for (int j = 0; j < p; j++)
        {
            cin >> t;
            m1[i].emplace_back(t);
        }
    }
    for (int i = 0; i < p; i++)
    {
        vector<long long> temp;
        m2.emplace_back(std::move(temp));
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            m2[i].emplace_back(t);
        }
    }
    for (int i = 0; i < n; i++)
    {
        t = 0;
        vector<long long> temp;
        res.emplace_back(std::move(temp));
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                t += m1[i][k] * m2[k][j];
            }
            res[i].push_back(t % MOD);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}