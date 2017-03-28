/*
ID: lxdlam1
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char *tobase(int base, int num);
int isPal(char src[]);
char *reverseString(char src[]);

int main()
{
    FILE *fin = fopen("palsquare.in", "r");
    FILE *fout = fopen("palsquare.out", "w");
    int base, i;
    fscanf(fin, "%d", &base);
    for (i = 0; i <= 300; i++)
    {
        if (isPal(tobase(base, i * i)))
            fprintf(fout, "%s %s\n", reverseString(tobase(base, i)), tobase(base, i * i));
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
        if (num % base <= 9)
            *(str + i) = num % base + '0';
        else
        {
            switch (num % base)
            {
            case 10:
                *(str + i) = 'A';
                break;
            case 11:
                *(str + i) = 'B';
                break;
            case 12:
                *(str + i) = 'C';
                break;
            case 13:
                *(str + i) = 'D';
                break;
            case 14:
                *(str + i) = 'E';
                break;
            case 15:
                *(str + i) = 'F';
                break;
            case 16:
                *(str + i) = 'G';
                break;
            case 17:
                *(str + i) = 'H';
                break;
            case 18:
                *(str + i) = 'I';
                break;
            case 19:
                *(str + i) = 'J';
                break;
            default:
                break;
            }
        }
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

char *reverseString(char src[])
{
    int i;
    char temp;
    for (i = 0; i < strlen(src) / 2; i++)
    {
        temp = src[i];
        src[i] = src[strlen(src) - 1 - i];
        src[strlen(src) - 1 - i] = temp;
    }
    return src;
}