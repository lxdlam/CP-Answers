#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 100 + 10;

int sch[SIZE][10] = {0};
int pro[SIZE][11] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int res = -(1 << 30);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            cin >> sch[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 11; j++)
            cin >> pro[i][j];

    for (int b = 1; b < (1 << 10); b++)
    {
        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < 10; j++)
                if ((b >> j & 1) && sch[i][j])
                    c++;
            cc += pro[i][c];
        }
        res = max(cc, res);
    }

    cout << res << endl;
    return 0;
}