#include <cstdio>
#include <cstring>

using namespace std;
const int size = 1e4 + 5;

int main()
{
    int games = 0, t, ans[size], guess[size], A, B, c1, c2;
    while (scanf("%d", &t) && t)
    {
        printf("Game %d:\n", ++games);
        for (int i = 0; i < t; i++)
            scanf("%d", &ans[i]);
        for (;;)
        {
            A = B = 0;
            for (int i = 0; i < t; i++)
            {
                scanf("%d", &guess[i]);
                if (ans[i] == guess[i])
                    A++;
            }
            if (guess[0] == 0)
                break;
            for (int i = 0; i <= 9; i++)
            {
                c1 = c2 = 0;
                for (int j = 0; j < t; j++)
                {
                    if (ans[j] == i)
                        c1++;
                    if (guess[j] == i)
                        c2++;
                }
                B += c1 > c2 ? c2 : c1;
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}