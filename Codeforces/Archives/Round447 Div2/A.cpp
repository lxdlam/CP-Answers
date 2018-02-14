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
    string t = "";
    char ch;
    while (cin >> ch)
    {
        if (ch == 'Q' || ch == 'A')
            t += ch;
    }
    int t1 = 0, t2 = 0;
    int res = 0;
    int tlen = t.size();
    for (int i = 0; i < tlen; i++)
    {
        t1 = t2 = 0;
        if (t[i] == 'A')
        {
            for (int j = 0; j < i; j++)
                if (t[j] == 'Q')
                    t1++;
            for (int j = i + 1; j < tlen; j++)
                if (t[j] == 'Q')
                    t2++;
        }

        res += t1 * t2;
    }

    cout << res << endl;

    return 0;
}