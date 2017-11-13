#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 2e5 + 10;

bool vis[SIZE] = {false};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (auto &i : v)
    {
        cin >> i;
        s.insert(i);
    }
    int meet = s.size();

    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        if (meet == 1 && !vis[*it])
        {
            cout << *it << endl;
            break;
        }
        if (!vis[*it])
        {
            vis[*it] = true;
            meet--;
        }
    }

    return 0;
}