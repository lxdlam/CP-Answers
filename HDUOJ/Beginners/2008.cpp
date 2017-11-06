#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    double t;
    int cp, cz, cn;
    while (cin >> n && n)
    {
        cp = cz = cn = 0;
        while (n--)
        {
            cin >> t;
            if (t > 0)
                cp++;
            else if (t < 0)
                cn++;
            else
                cz++;
        }
        cout << cn << " " << cz << " " << cp << endl;
    }
    return 0;
}