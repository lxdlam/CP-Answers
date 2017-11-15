#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int SIZE = 15 + 5;

int board[SIZE][SIZE] = {0};
int temp[SIZE][SIZE] = {0};
int ans[SIZE][SIZE] = {0};

int dir[5][2] = {
    {-1, 0},
    {0, -1},
    {0, 0},
    {0, 1},
    {1, 0}};

int m, n;

int check(int x, int y)
{
    int t = board[x][y];
    int tx, ty;
    for (int i = 0; i < 5; i++)
    {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (0 <= tx && tx < m && 0 <= ty && ty < n)
            t += temp[tx][ty];
    }

    return t % 2;
}

int calc()
{
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i - 1, j) != 0)
                temp[i][j] = 1;
        }
    }

    for (int j = 0; j < n; j++)
        if (check(m - 1, j) != 0)
            return -1;

    int res = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res += temp[i][j];

    return res;
}

void solve()
{
    int res = -1;

    for (int i = 0; i < 1 << n; i++)
    {
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < n; j++)
            temp[0][n - j - 1] = i >> j & 1;

        int num = calc();
        if (num >= 0 && (res < 0 || res > num))
        {
            res = num;
            memcpy(ans, temp, sizeof(temp));
        }
    }

    if (res < 0)
        cout << "IMPOSSIBLE" << endl;
    else
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cout << ans[i][j] << (j == n - 1 ? "\n" : " ");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    solve();

    return 0;
}