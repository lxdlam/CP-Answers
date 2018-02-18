#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int res = 1;
    while (res < k && n)
    {
        res *= 2;
        n--;
    }
    while (n--)
    {
        res += k;
    }
    cout << res << endl;
    return 0;
}