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
    int t;
    bool flag;
    cin >> n;
    while (n--)
    {
        cin >> t;
        flag = false;
        if (t % 3 == 0 || t % 7 == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            for (int i = 0; i < 35 && 3 * i < t; i++)
            {
                if ((t - 3 * i) % 7 == 0)
                {
                    cout << "YES" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}