#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 30 + 10;

int s[SIZE] = {3};

void init()
{
    for (int i = 1; i < SIZE; i++)
        s[i] = 2 * s[i - 1] - 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int n;
    int t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        cout << s[t] << endl;
    }

    return 0;
}