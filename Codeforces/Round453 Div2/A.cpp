#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 100 + 10;

int line[SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    int x, y;
    int s = 0, e = 0;
    cin >> m >> n;
    while (m--)
    {
        cin >> x >> y;
        if (s >= x && s <= y)
            s = x;
        if (e <= y && e >= x)
            e = y;
    }
    if (s == 0 && e == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}