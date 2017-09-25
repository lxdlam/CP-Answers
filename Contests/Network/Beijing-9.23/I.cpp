#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define MEM(x) memset(x, 0, sizeof(x));

using namespace std;

const int SIZE = 131072 + 10;

int arr[SIZE] = {0};
int tree[SIZE] = {0};

inline int lowbit(int t)
{
    return t & (-t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, k, t, op, a, b;
    int n;
    cin >> T;
    while (T--)
    {
        MEM(arr);
        MEM(tree);
        cin >> k;
        n = pow(2, k);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> t;
        while (t--)
        {
            cin >> op >> a >> b;
            switch (op)
            {
            case 1:
                cout << solve(arr, a, b) << endl;
                break;
            case 2:
                arr[a] = b;
                break;
            }
        }
    }
    return 0;
}