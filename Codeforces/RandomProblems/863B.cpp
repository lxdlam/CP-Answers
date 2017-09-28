#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int diff(vector<int> &v)
{
    int res = 0;
    for (int i = 0; i < v.size(); i += 2)
        res += v[i + 1] - v[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    vector<int> temp;
    int res = 2147483647, total = 0;
    int n, t;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            temp.clear();
            for (int k = 0; k < 2 * n; k++)
                if (k != i && k != j)
                    temp.push_back(v[k]);
            res = min(res, diff(temp));
        }
    }
    cout << res << endl;
    return 0;
}