/*
ID: lxdlam1
LANG: C
TASK: milk
*/
#include <stdio.h>

typedef struct tagSeller
{
    int unit_price;
    int quantity;
} Seller;

int main()
{
    FILE *fin = fopen("milk.in", "r");
    FILE *fout = fopen("milk.out", "w");
    int amount, n, i, j, total = 0;
    Seller seller[5001] = {0}, temp;
    fscanf(fin, "%d %d", &amount, &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%d %d", &seller[i].unit_price, &seller[i].quantity);
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (seller[j].unit_price > seller[j + 1].unit_price)
            {
                temp = seller[j + 1];
                seller[j + 1] = seller[j];
                seller[j] = temp;
            }
        }
    }
    for (i = 0; amount > 0; i++)
    {
        if (seller[i].quantity >= amount)
        {
            total += amount * seller[i].unit_price;
            amount = 0;
        }
        else
        {
            total += (seller[i].unit_price * seller[i].quantity);
            amount -= seller[i].quantity;
        }
    }
    fprintf(fout, "%d\n", total);
    fclose(fin);
    fclose(fout);
    return 0;
}