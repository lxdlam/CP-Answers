#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<char, double> m;

void init()
{
    m['H'] = 1.008;
    m['C'] = 12.01;
    m['O'] = 16;
    m['N'] = 14.01;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    string t;
    int pos, temp;
    double res;
    char cur;
    cout << setprecision(3) << fixed;
    while (T--)
    {
        cin >> t;
        res = 0;
        pos = 0;
        while (pos < t.size())
        {
            if (isalpha(t[pos]))
            {
                temp = 0;
                cur = t[pos++];
                res += m[cur];
                while (isdigit(t[pos]))
                    temp = temp * 10 + t[pos++] - '0';
                res += (temp == 0 ? 0 : temp - 1) * m[cur];
            }
        }
        cout << res << endl;
    }
    return 0;
}