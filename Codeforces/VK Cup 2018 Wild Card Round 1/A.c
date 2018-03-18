#include <stdio.h>

#define SIZE 1000

long long two[32];
long long three[21];
long long num[SIZE];
int si;

void init()
{
    two[0] = three[0] = 1;
    for (int i = 1; i < 32; i++)
        two[i] = two[i - 1] * 2LL;

    for (int i = 1; i < 21; i++)
        three[i] = three[i - 1] * 3LL;
    si = 0;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 21; j++)
            num[si++] = two[i] * three[j];
    }
}

int main()
{
    long long x, y;
    init();
    scanf("%I64d %I64d", &x, &y);
    int cnt = 0;
    for (int i = 0; i < si; i++)
        if (x <= num[i] && num[i] <= y)
            cnt++;
    printf("%d\n", cnt);
}