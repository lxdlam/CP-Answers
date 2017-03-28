/*
ID: lxdlam1
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

typedef struct tagDistance
{
    int distance;
    int point;
} Distance;

int main()
{
    FILE *fin = fopen("barn1.in", "r");
    FILE *fout = fopen("barn1.out", "w");
    int m, s, c, i, j, total = 0, tmp_start, tmp_end, numTmp;
    int stalls[MAX_LENGTH] = {0};
    Distance distances[MAX_LENGTH] = {0}, tmp;
    fscanf(fin, "%d %d %d", &m, &s, &c);
    for (i = 0; i < c; i++)
        fscanf(fin, "%d", &stalls[i]);
    for (i = 0; i < c - 1; i++)
    {
        for (j = 0; j < c - 1; j++)
        {
            if (stalls[j] > stalls[j + 1])
            {
                numTmp = stalls[j];
                stalls[j] = stalls[j + 1];
                stalls[j + 1] = numTmp;
            }
        }
    }
    for (i = 0; i < c; i++)
    {
        distances[i].distance = stalls[i + 1] - stalls[i];
        distances[i].point = i;
    }
    for (i = 0; i < c - 1; i++)
    {
        for (j = 0; j < c - 1; j++)
        {
            if (distances[j].distance < distances[j + 1].distance)
            {
                tmp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tmp;
            }
        }
    }
    if (m > c)
        m = c;
    for (i = 0; i < m - 2; i++)
    {
        for (j = 0; j < m - 2; j++)
        {
            if (distances[j].point > distances[j + 1].point)
            {
                tmp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tmp;
            }
        }
    }
    tmp_start = 0;
    for (i = 0; i < m - 1; i++)
    {
        tmp_end = distances[i].point;
        total += stalls[tmp_end] - stalls[tmp_start] + 1;
        tmp_start = distances[i].point + 1;
    }
    total += stalls[c - 1] - stalls[tmp_start] + 1;
    fprintf(fout, "%d\n", total);
    fclose(fin);
    fclose(fout);
    return 0;
}
