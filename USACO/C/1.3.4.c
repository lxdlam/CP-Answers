/*
ID: lxdlam1
LANG: C
TASK: combo
*/
#include <stdio.h>
#include <assert.h>

int checkArray(int src[200], int target, int candidate, int n);

int main()
{
    FILE *fin = fopen("combo.in", "r");
    FILE *fout = fopen("combo.out", "w");
    assert(fin == NULL || fout == NULL);
    int n, pass1[3] = {0}, pass2[3] = {0}, count = 0, i, j, k, pass_array[200] = {0};
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d %d %d", &pass1[0], &pass1[1], &pass1[2]);
    fscanf(fin, "%d %d %d", &pass2[0], &pass2[1], &pass2[2]);
    for (i = 0; i < n; i++)
    {
        pass_array[i] = i + 1;
        pass_array[i + n] = i + 1;
    }
    if (n <= 5)
        fprintf(fout, "%d\n", n * n * n);
    else
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                for (k = 1; k <= n; k++)
                {
                    if (checkArray(pass_array, pass1[0], i, n))
                    {
                        if (checkArray(pass_array, pass1[1], j, n))
                        {
                            if (checkArray(pass_array, pass1[2], k, n))
                            {
                                if (checkArray(pass_array, pass2[0], i, n))
                                {
                                    if (checkArray(pass_array, pass2[1], j, n))
                                    {
                                        if (checkArray(pass_array, pass2[2], k, n))
                                        {
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        fprintf(fout, "%d\n", 250 - count);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

int checkArray(int src[200], int target, int candidate, int n)
{
    int i;
    if (target < 3)
        i = target + n - 1;
    else
        i = target - 1;
    if (candidate == src[i - 2])
        return 1;
    else if (candidate == src[i - 1])
        return 1;
    else if (candidate == src[i])
        return 1;
    else if (candidate == src[i + 1])
        return 1;
    else if (candidate == src[i + 2])
        return 1;
    else
        return 0;
}