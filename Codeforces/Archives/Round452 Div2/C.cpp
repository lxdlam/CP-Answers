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
    int n;
    cin >> n;
    cout << n * 1LL * (n + 1) / 2 % 2 << endl
         << n / 2 << " ";
    for (int i = n, j = 0; i > 1; i -= 2, j = !j)
        cout << i - j << " ";
    cout << endl;
    return 0;
}