#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100 + 10;

long dd[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    string t;

    for (int i = 0; i < SIZE; i++)
        dd[i] = 200;

    cin >> n >> d >> t;

    dd[0] = 0;

    for (int i = 1; i < n; i++)
    // dp to find the shortest method
        for (int j = i - d >= 0 ? i - d : 0; j < i; j++)
            if (t[j] == '1')
                dd[i] = min(dd[i], dd[j] + 1);

    cout << (dd[n - 1] > 100 ? -1 : dd[n - 1]) << endl;
    return 0;
}