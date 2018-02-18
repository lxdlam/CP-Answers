#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 11 + 1;

int mps[SIZE][SIZE] = {0};

void floyd()
{
    for (int k = 0; k <= 9; k++)
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                mps[i][j] = min(mps[i][j], mps[i][k] + mps[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    int res = 0;
    int t;

    cin >> h >> w;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            cin >> mps[i][j];

    floyd();

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> t;
            if (t == -1 || t == 1)
                continue;
            res += mps[t][1];
        }

    cout << res << endl;

    return 0;
}