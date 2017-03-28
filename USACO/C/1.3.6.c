/*
ID: lxdlam1
LANG: C
TASK: skidesign
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    FILE *fin = fopen("skidesign.in", "r");
    FILE *fout = fopen("skidesign.out", "w");
    int numCount, hills[MAX_SIZE], ans = 2147483647, tmp;
    fscanf(fin, "%d", &numCount);
    for (int i = 0; i < numCount; i++)
        fscanf(fin, "%d", &hills[i]);
    for (int i = 1; i <= 83; i++)
    {
        tmp = 0;
        for (int j = 0; j < numCount; j++)
        {
            if (hills[j] < i)
                tmp += (i - hills[j]) * (i - hills[j]);
            if (hills[j] > i + 17)
                tmp += (hills[j] - i - 17) * (hills[j] - i - 17);
        }
        ans = ans > tmp ? tmp : ans;
    }
    fprintf(fout, "%d\n", ans);
    fclose(fin);
    fclose(fout);
    return 0;
}