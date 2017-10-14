#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> mat;

int n, m, k;

int cal(vector<int> v, int i)
{
    int res = 0;
    int len = min(n - i, k);
    for (int j = i; j < len + i; j++)
        res += v[j];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, pos, sum, res = 0, step = 0, count;
    cin >> n >> m >> k;
    mat b(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            b[j].emplace_back(t);
        }
    }
    for (auto i : b)
    {
        pos = count = sum = 0;
        for (int j = 0; j < i.size(); j++)
        {
            if (i[j] == 1)
            {
                pos++;
                t = cal(i, j);
                if (t > sum)
                {
                    count = pos - 1;
                    sum = t;
                }
            }
        }
        res += sum;
        step += count;
    }
    cout << res << " " << step << endl;
    return 0;
}