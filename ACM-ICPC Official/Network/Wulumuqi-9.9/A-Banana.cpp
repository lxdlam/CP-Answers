#include <cstdio>
#include <cstring>

const int MAX = 50 + 5;

int b[MAX][MAX] = {0};
int p[MAX][MAX] = {0};

inline void set0()
{
    memset(b, 0, sizeof(b));
    memset(p, 0, sizeof(p));
}

int main()
{
    int T;
    int n, m;
    int x, y;
    scanf("%d", &T);
    while (T--)
    {
        set0();
        bool isNewline = true;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            b[x][y] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            p[x][y] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int k = 1; k <= m; k++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (b[i][j] == p[j][k] && b[i][j] == 1)
                    {
                        if (isNewline)
                        {
                            printf("%d %d", i, k);
                            isNewline = false;
                        }
                        else
                        {
                            printf("\n%d %d", i, k);
                        }
                        break;
                    }
                }
            }
        }
    }
    return 0;
}