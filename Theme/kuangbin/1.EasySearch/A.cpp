#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

char board[9][9];
bool vis[9] = {false};

int n, res;

void dfs(int row, int m)
{
    if (m == 0)
    {
        res++;
        return;
    }
    if (row >= n)
    {
        return;
    }
    dfs(row + 1, m);
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == '#' && !vis[i])
        {
            vis[i] = true;
            dfs(row + 1, m - 1);
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    while (cin >> n >> m && n != -1)
    {
        cin.get();
        res = 0;
        memset(board, 0, sizeof(board));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
            cin.get();
        }
        dfs(0, m);
        cout << res << endl;
    }

    return 0;
}