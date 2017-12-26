#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    si s, m;
    int n;
    cin >> n;
    vi v(n);
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (auto &i : v)
    {
        cin >> i;
        s.erase(i);
    }

    int i = 0;
    for (auto &i : v)
    {
        if (!m.count(i) && i <= n)
            m.insert(i);
        else
        {
            i = *s.begin();
            m.insert(i);
            s.erase(i);
        }
    }

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}