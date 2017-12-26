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
    int v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (int i = 200; i >= 1; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            for (int k = j - 1; k >= 1; k--)
            {
                if (vm <= i && 2 * v1 >= i && v1 <= i && vm * 2 < i)
                    if (vm <= j && 2 * v2 >= j && v2 <= j && vm * 2 < j)
                        if (vm <= k && vm * 2 >= k && v3 <= k && 2 * v3 >= k)
                            return cout << i << endl
                                        << j << endl
                                        << k << endl,
                                   0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}