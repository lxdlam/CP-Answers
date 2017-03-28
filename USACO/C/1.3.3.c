/*
ID: lxdlam1
LANG: C
TASK: crypt1
*/
#include <stdio.h>

int numberLength(int num);
int check(int *numbers, int srcNumber, int numbersCount, int srcCount);

int main()
{
    FILE *fin = fopen("crypt1.in", "r");
    FILE *fout = fopen("crypt1.out", "w");
    int n, count = 0, numbers[110] = {0};
    int i, j;
    int partial1 = 0, partial2 = 0, answer = 0;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%d", numbers + i);
    for (i = 100; i <= 999; i++)
    {
        for (j = 10; j <= 99; j++)
        {
            partial1 = i * (j % 10);
            partial2 = i * (int)(j / 10);
            answer = i * j;
            if (numberLength(partial1) != 3 || numberLength(partial2) != 3)
                continue;
            if (check(numbers, i, n, 3) && check(numbers, j, n, 2) && check(numbers, partial1, n, 3) && check(numbers, partial2, n, 3) && check(numbers, answer, n, 4))
                count++;
        }
    }
    fprintf(fout, "%d\n", count);
    fclose(fin);
    fclose(fout);
    return 0;
}

int numberLength(int num)
{
    int n = 0;
    while (num)
    {
        num /= 10;
        n++;
    }
    return n;
}

int check(int *numbers, int srcNumber, int numbersCount, int srcCount)
{
    int flag = 1, i, j;
    char src[50] = {0};
    sprintf(src, "%d", srcNumber);
    for (i = 0; i <= srcCount; i++)
    {
        if (!flag)
            return 0;
        flag = 0;
        for (j = 0; j < numbersCount; j++)
        {
            if (src[i] - '0' == numbers[j])
            {
                flag = 1;
                break;
            }
        }
    }
    return 1;
}
