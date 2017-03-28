#include <iostream>
#include <cstdlib>
#include "UF.h"

using namespace std;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 4;
const int RIGHT = 8;

const int Blocks[11] = {UP | LEFT, UP | RIGHT, LEFT | DOWN, RIGHT | DOWN, UP | DOWN, LEFT | RIGHT, UP | LEFT | RIGHT, LEFT | UP | DOWN, DOWN | LEFT | RIGHT, RIGHT | UP | DOWN, UP | DOWN | LEFT | RIGHT};

int Bits(int, int);

int main()
{
    int size;
    int m, n;
    while (cin >> m >> n)
    {
        cin.get();
        if (m == -1)
            break;
        UFO ufo(n * m);
        int *temp = new int[n * m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                temp[i * n + j] = cin.get() - 'A';
            cin.get();
        }
        for (int i = 0; i < m * n; i++)
        {
            if (i + n < m * n && Bits(Blocks[temp[i]], 2) && Bits(Blocks[temp[i + n]], 1) && !ufo.connected(i, i + n))
                ufo.Union(i, i + n);
            if (i % n + 1 < n && Bits(Blocks[temp[i]], 4) && Bits(Blocks[temp[i + 1]], 3) && !ufo.connected(i, i + 1))
                ufo.Union(i, i + 1);
        }
        cout << ufo.getCount() << endl;
        cin.get();
    }
    return 0;
}

int Bits(int n, int m)
{
    return (n >> (m - 1)) & 1;
}