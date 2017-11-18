#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sum, t;
    while (cin >> n)
    {
        sum = 0;
        while (n--)
        {
            cin >> t;
            sum += t;
        }
        cout << sum << endl;
    }
    return 0;
}