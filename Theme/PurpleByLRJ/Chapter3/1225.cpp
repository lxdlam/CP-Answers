#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 10;

int cnt[SIZE];
int t;

void helper(int n)
{
    while (n)
    {
        cnt[n % 10]++;
        n /= 10;
    }
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= t; i++)
        helper(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> t;
        solve();
        for (int i = 0; i < SIZE; i++)
            cout << (i == 0 ? "" : " ") << cnt[i];
        cout << endl;
    }
    return 0;
}