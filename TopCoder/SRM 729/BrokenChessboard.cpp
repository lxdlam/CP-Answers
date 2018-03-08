#include <bits/stdc++.h>

using namespace std;

class BrokenChessboard
{
  private:
    // Constants
    vector<string> board;
    const static int SIZE = 50 + 10;
    int n, m;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool vis[SIZE][SIZE] = {{false}};

    // Useful Inner Method
    bool check(int i, int j)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return !vis[i][j];
    }

    int dfs(int i, int j, int s)
    {
        int res = 0;
        if (!check(i, j))
            return 0;
        vis[i][j] = true;
        if (s && board[i][j] == 'W')
            res++;
        else if (!s && board[i][j] == 'B')
            res++;
        for (int k = 0; k < 4; k++)
            res += dfs(i + dir[k][0], j + dir[k][1], !s);
        return res;
    }

    // Builder
    void build()
    {
    }

    // Solver
  public:
    int minimumFixes(vector<string> _board)
    {
        build();

        board = _board;
        n = _board.size();
        m = _board[0].size();
        int res = dfs(0, 0, 0);
        memset(vis, false, sizeof(vis));
        res = min(res, dfs(0, 0, 1));

        return res;
    }
};