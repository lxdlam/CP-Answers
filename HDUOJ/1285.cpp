// not solved
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 500 + 10;

int g[SIZE][SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> res;
    int n, m;
    int l, r;
    bool first = false;
    cin >> n >> m;
    while (m--)
    {
        cin >> l >> r;
        g[l][r] = 1;
        g[r][0]++;
    }
    while (res.size() != n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (g[i][0] == 0)
            {
                res.push_back(i);
                g[i][0] = -1;
                for (int j = 1; j <= n; j++)
                {
                    if (g[i][j])
                        g[j][0]--;
                }
                break;
            }
        }
    }
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << " ";
    cout << res[res.size() - 1] << endl;
    return 0;
}