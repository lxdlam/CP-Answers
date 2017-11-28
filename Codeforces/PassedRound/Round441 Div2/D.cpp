#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 300000 + 10;

int v[SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, count, j;
    cin >> n;
    cout << 1 << " ";
    j = n - 1;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v[t - 1] = 1;
        if (t - 1 == j)
        {
            while (v[j] != 0)
                j--;
            count = n - j - 1;
        }
        cout << i - count + 2 << " ";
    }
    cout << endl;

    return 0;
}