#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

bool suff(const string &a, const string &b)
{
    if (a.size() < b.size())
        return false;
    for (int i = b.size() - 1, j = a.size() - 1; i >= 0; i--, j--)
    {
        if (a[j] != b[i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, set<string>> m;
    int n, k;
    string t;
    string te;
    bool flag;
    cin >> n;
    while (n--)
    {
        cin >> t >> k;
        while (k--)
        {
            cin >> te;
            m[t].insert(te);
        }
    }
    set<string> s;
    for (auto &i : m)
    {
        s.clear();
        for (auto l : i.second)
        {
            for (auto r : i.second)
            {
                if (l == r)
                    continue;
                if (suff(l, r))
                    s.insert(r);
                if (suff(r, l))
                    s.insert(l);
            }
        }
        for (auto j : s)
            i.second.erase(j);
    }
    cout << m.size() << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second.size() << " ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}