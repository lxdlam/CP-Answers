#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<pair<int, int>, int> ma;
    int n, m;
    int cnt = 0;
    bool flag;
    while (cin >> n >> m)
    {
        cnt++;
        if (n > m)
            swap(n, m);
        ma[make_pair(n, m)]++;
        if (cnt == 6)
        {
            flag = true;
            for (auto i : ma)
                if (i.second % 2)
                {
                    flag = false;
                    break;
                }
            cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << endl;
            ma.clear();
            cnt = 0;
        }
    }
    return 0;
}