#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    int T;
    int n, m;
    cin >> T;
    while (T--)
    {
        v.clear();
        cin >> n >> m;
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        if ((n + m) >> 1 > v.size())
            cout << 9 << endl;
        else
            cout << v[(n + m) >> 1] << endl;
    }
    return 0;
}