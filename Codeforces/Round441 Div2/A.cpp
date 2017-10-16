#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    int res = 0;
    cin >> n >> a >> b >> c;
    if (n == 1)
        cout << 0 << endl;
    else
    {
        n -= 2;
        res += a > b ? b : a;
        if (res == a)
            res += (a > c ? c : a) * n;
        else if (res == b)
            res += (b > c ? c : b) * n;
        cout << res << endl;
    }
    return 0;
}