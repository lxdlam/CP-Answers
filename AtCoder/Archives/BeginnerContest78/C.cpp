#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 100 + 10;

ll n[SIZE] = {1};

void init()
{
    for (int i = 1; i < SIZE; i++)
        n[i] = 2 * n[i - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int a, b;
    cin >> a >> b;
    cout << (1900 * b + (a - b) * 100) * n[b] << endl;

    return 0;
}