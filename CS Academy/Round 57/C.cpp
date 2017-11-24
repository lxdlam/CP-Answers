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

    int n, k;
    int p;
    int m1, m2;
    m1 = m2 = 0;
    cin >> n >> k;

    vi v(n + 1, 0);

    for (int i = 0; i < k; i++)
    {
        cin >> p;
        v[p] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> p;
        v[p] = 2;
    }

    // match clockwisely
    for (int i = 1; i < n; i++)
    {
        if (v[i] + v[i + 1] == 3)
        {
            m1++;
            i++;
        }
    }

    // match anti-clockwisely
    if (v[1] + v[n] == 3)
        m2++;
    for (int i = n - 1; i > 2; i--)
    {
        if (v[i] + v[i - 1] == 3)
        {
            m2++;
            i--;
        }
    }

    cout << 2 * k - max(m1, m2) << endl;

    return 0;
}