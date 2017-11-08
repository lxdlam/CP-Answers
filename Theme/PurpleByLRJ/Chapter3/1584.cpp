#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string t;
int pos, tlen;

void solve()
{
    tlen = t.size();
    pos = 0;
    for (int i = 1; i < tlen; i++)
    {
        for (int j = 0; j < tlen; j++)
        {
            if (t[(i + j) % tlen] < t[(pos + j) % tlen])
            {
                pos = i;
                break;
            }
            else if (t[(i + j) % tlen] > t[(pos + j) % tlen])
                break;
        }
    }
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
        t.clear();
        cin >> t;
        solve();
        for (int i = 0; i < tlen; i++)
            cout << t[(i + pos) % tlen];
        cout << endl;
    }
    return 0;
}