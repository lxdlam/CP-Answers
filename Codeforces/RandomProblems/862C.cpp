#include <iostream>

using namespace std;

// n<=1e5
// 1e5 = 1100011010100000 (2)
const int a = 1 << 17;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, t = 0;
    cin >> n >> x;
    if (n == 1)
        cout << "YES" << endl
             << x << endl;
    else if (n == 2)
    {
        if (x == 0)
            cout << "NO" << endl;
        else
            cout << "YES\n0 " << x << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i <= n - 3; i++)
        {
            cout << i << " ";
            t ^= i;
        }
        cout << a << " " << (a ^ t ^ x) << endl;
    }
    return 0;
}