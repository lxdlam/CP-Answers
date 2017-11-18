#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    while (cin >> a >> b)
    {
        if (a == b && a == 0)
            break;
        cout << a + b << endl;
    }
    return 0;
}