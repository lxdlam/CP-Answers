#include <cstdio>
#include <cstring>

using namespace std;

const int size = 100;
char grid[size][size] = {0};

void mark(const int &x, const int &y)
{
    if (grid[x][y] == '*' || grid[x][y] == 0 || x < 0 || x >= size || y < 0 || y >= size)
        return;
    else
    {
        grid[x][y] = '*';
        mark(x - 1, y - 1);
        mark(x - 1, y);
        mark(x - 1, y + 1);
        mark(x, y - 1);
        mark(x, y + 1);
        mark(x + 1, y - 1);
        mark(x + 1, y);
        mark(x + 1, y + 1);
    }
}

int main()
{
    int n, m, count;
    while (scanf("%d%d", &n, &m) && n != 0 && m != 0)
    {
        getchar();
        count = 0;
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                scanf("%c", &grid[i][j]);
            getchar();
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '@')
                    count++, mark(i, j);
        printf("%d\n", count);
    }
    return 0;
}