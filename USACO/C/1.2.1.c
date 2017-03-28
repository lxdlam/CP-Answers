/*
ID: lxdlam1
LANG: C
TASK: milk2
*/
#include <stdio.h>

int max(int a, int b);

typedef struct time
{
    int start;
    int end;
} Time;

int main()
{
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    int n, i, j, maxWorking = 0, maxFree = 0, tmp_start = 0, tmp_end = 0, flag = 1;
    Time times[5001] = {0}, tmp;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%d %d", &times[i].start, &times[i].end);
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (times[j - 1].start > times[j].start)
            {
                tmp = times[j - 1];
                times[j - 1] = times[j];
                times[j] = tmp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (times[i].start <= tmp_end)
            tmp_end = max(tmp_end, times[i].end);
        else
        {
            tmp_start = times[i].start;
            tmp_end = times[i].end;
        }
        maxWorking = max(maxWorking, tmp_end - tmp_start);
        maxFree = max(maxFree, times[i + 1].start - tmp_end);
    }
    fprintf(fout, "%d %d\n", maxWorking, maxFree);
    fclose(fin);
    fclose(fout);
    return 0;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}