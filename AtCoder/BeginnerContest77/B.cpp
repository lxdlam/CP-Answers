#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10;

long long n[SIZE] = {0};

void init()
{
    for (long long i = 0; i < SIZE; i++)
        n[i] = i * i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long k;
    init();
    cin >> k;
    for (long long i = 0; i < SIZE; i++)
    {
        if (k == n[i])
        {
            cout << k << endl;
            break;
        }
        else if (k > n[i] && k < n[i + 1])
        {
            cout << n[i] << endl;
            break;
        }
    }
    return 0;
}