#include <iostream>
#include <vector>

using namespace std;

using grid = vector<vector<char>>;

int search(grid &g, int i, int j)
{
    if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || (g[i][j] <= '9' && g[i][j] >= '0'))
        return 0;
    if (g[i][j] == '#')
        return 1;
    g[i][j] = '0';
    g[i][j] += search(g, i - 1, j) +
               search(g, i - 1, j - 1) +
               search(g, i - 1, j + 1) +
               search(g, i, j - 1) +
               search(g, i, j + 1) +
               search(g, i + 1, j - 1) +
               search(g, i + 1, j) +
               search(g, i + 1, j + 1);
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    char t;
    cin >> h >> w;
    grid g(h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> t;
            g[i].emplace_back(t);
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (g[i][j] == '.')
                search(g, i, j);
    for (auto i : g)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }
    return 0;
}