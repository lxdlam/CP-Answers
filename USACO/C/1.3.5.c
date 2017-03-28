/*
ID: lxdlam1
LANG: C
TASK: wormhole
*/
#include <stdio.h>

#define MAX_SIZE 12

int countPoint(int board[MAX_SIZE][MAX_SIZE], int numRow);
int pow(int base, int exponent);

int main()
{
    FILE *fin = fopen("wormhole.in", "r");
    FILE *fout = fopen("wormhole.out", "w");
    int n, i, j, tmp, count = 0;
    int answer = 1;
    int board[MAX_SIZE][MAX_SIZE] = {0};
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%d %d", &i, &j);
        board[i][j] = 1;
    }
    for (i = 0; i < MAX_SIZE; i++)
    {
        tmp = countPoint(board, i);
        if (tmp >= 2)
        {
            answer *= pow(2, (tmp - 1) / 2);
            count++;
        }
    }
    fprintf(fout, "%d\n", answer *= pow(2, count - 1));
    fclose(fin);
    fclose(fout);
    return 0;
}

int countPoint(int board[MAX_SIZE][MAX_SIZE], int numRow)
{
    int i, count = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (board[numRow][i])
            count++;
    }
    return count;
}

int pow(int base, int exponent)
{
    int i, ans = 1;
    if (!exponent)
        return 1;
    for (i = 0; i < exponent; i++)
        ans *= base;
    return ans;
}