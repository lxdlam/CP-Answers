#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string t;
    while (cin >> t)
    {
        sort(t.begin(), t.end());
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                cout << t[i];
            else
                cout << " " << t[i];
        }
        cout << endl;
    }

    return 0;
}