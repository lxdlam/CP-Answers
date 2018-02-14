#include <bits/stdc++.h>

using namespace std;

bool vis[999] = {false};

int main()
{
    int n, t;
    cin >> n;
    vector<vector<int>> v(3);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> t;
            v[i].emplace_back(t);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            vis[v[i][j]] = true;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    for (int l = 0; l < 6; l++)
                        vis[v[i][j] * 10 + v[k][l]] = true;
                }
            }
        }
    }
    for (int i = 1; i < 999; i++)
    {
        if (!vis[i])
        {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}