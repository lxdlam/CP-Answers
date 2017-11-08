#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(const string &s, int i)
{
    if (s.size() % i)
        return false;
    for (int j = 0; j < s.size() - i; j++)
        if (s[j] != s[j + i])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, tlen;
    bool flag;
    cin >> T;
    string t;
    while (T--)
    {
        cin >> t;
        tlen = t.size();
        for (int i = 1; i <= tlen; i++)
            if (check(t, i))
            {
                cout << i << "\n"
                     << (T == 0 ? "" : "\n");
                break;
            }
    }
    return 0;
}