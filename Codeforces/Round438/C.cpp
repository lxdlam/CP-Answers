#include <iostream>

using namespace std;

const int SIZE = 4;

int q[SIZE] = {0, 0, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    int temp;
    bool flag = true;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> temp;
            q[j] += temp;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (q[i] > n / 2)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}