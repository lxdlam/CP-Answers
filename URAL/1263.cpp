#include <iostream>
#include <cstdio>

using namespace std;

int a[10001] = {0};

int main()
{
    int n, m;
    int *id;
    int temp, k;
    float answer;
    while (cin >> n >> m)
    {
        k = m;
        while (k--)
        {
            cin >> temp;
            a[temp]++;
        }
        for (int i = 1; i < n + 1; i++)
            printf("%.2f%%\n", (float)a[i] / m * 100);
    }
    return 0;
}