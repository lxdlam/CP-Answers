#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 1e5 + 10;

ll t[SIZE] = {1};

ll b[SIZE] = {0};

void init()
{
    for (int i = 1; i < SIZE; i++)
        t[i] = t[i - 1] * 2;
    for (int i = 1; i < SIZE; i++)
        b[i] = (t[i] - 1) * t[i - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    ll n;
    ll res = 1;

    cin >> n;

    for (int i = 1; n >= b[i]; i++)
        if (n % b[i] == 0)
            res = b[i];

    cout << res << endl;

    return 0;
}