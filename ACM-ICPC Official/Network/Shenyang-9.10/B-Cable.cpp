#include <cstdio>

using namespace std;

int main()
{
    int m, k;
    while (scanf("%d%d", &m, &k) == 2)
    {
        if (m <= k)
        {
            printf("%d\n", k);
            continue;
        }
        //懒得做了
    }
    return 0;
}