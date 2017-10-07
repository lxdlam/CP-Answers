#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    if (m == n)
        cout << "1" << endl;
    else if (m - n >= 10)
        cout << "0" << endl;
    else
    {
        int res = 1;
        int e = m % 10;
        int s = n % 10 + 1;
        if (e < s)
            res = 0;
        else
            for (; s <= e; s++)
            {
                res = (res * s) % 10;
            }
        cout << res << endl;
    }
    return 0;
}