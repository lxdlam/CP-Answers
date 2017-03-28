/*
ID: lxdlam1
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char *tobase(int base, int num);
int isPal(char src[]);

int main()
{
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");
    int n, s, i, j, count;
    fscanf(fin, "%d %d", &n, &s);
    for (i = s + 1; n > 0; i++)
    {
        count = 0;
        for (j = 2; j <= 10; j++)
        {
            if (isPal(tobase(j, i)))
                count++;
        }
        if (count >= 2)
        {
            n--;
            fprintf(fout, "%d\n", i);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

char *tobase(int base, int num)
{
    int i;
    char *str = (char *)calloc(32, sizeof(char));
    for (i = 0; num > 0; i++)
    {
        *(str + i) = num % base + '0';
        num /= base;
    }
    return str;
}

int isPal(char src[])
{
    int i;
    for (i = 0; i <= strlen(src) / 2; i++)
    {
        if (src[i] != src[strlen(src) - 1 - i] || src[0] == '\0')
            return 0;
    }
    return 1;
}
