#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, x, p, q;
    vi cats;
    while (cin >> m >> n >> x)
    {
        p = m, q = 0;
        cats.clear();
        cats.resize(n);
        for (int i = 0; i < n; i++)
            cin >> cats[i];

        sort(cats.begin(), cats.end());

    }

    return 0;
}