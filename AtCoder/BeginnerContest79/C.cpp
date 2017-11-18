#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string n;
    cin >> n;
    int a, b, c, d;
    a = n[0] - '0';
    b = n[1] - '0';
    c = n[2] - '0';
    d = n[3] - '0';
    bool found = false;
    int res;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res = a;
                if (i)
                    res += b;
                else
                    res -= b;
                if (j)
                    res += c;
                else
                    res -= c;
                if (k)
                    res += d;
                else
                    res -= d;
                if (res == 7)
                {
                    cout << a << (i ? '+' : '-') << b << (j ? '+' : '-') << c << (k ? '+' : '-') << d << "=7" << endl;
                    return 0;
                }
            }
        }
    }
}