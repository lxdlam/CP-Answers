#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e6 + 10;

// Factorials
long long n[SIZE] = {1};

void getFac()
{
    for (int i = 1; i < SIZE; i++)
        n[i] = n[i - 1] * i;
}

// Combinations
long long c[SIZE][SIZE] = {0};

void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            // Will be extremely large!
    }
}