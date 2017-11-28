#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x, t;
    bool cmp = false;
    cin >> n >> k >> x;
    int res = 0;
    while (n--)
    {
        if (n < k)
        cmp = true;
        cin >> t;
        if (!cmp)
            res += t;
        else
        {
            if (x > t)
                res += t;
            else
                res += x;
        }
    }
    cout << res << endl;
    return 0;
}