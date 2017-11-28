#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, t;
    int a = 0, b = 0, ac = 0, bc = 0;
    cin >> T;
    while (T--)
    {
        cin >> t;
        if (a == 0)
        {
            a = t;
            ac++;
        }
        else if (a == t)
        {
            ac++;
        }
        else if (b == 0)
        {
            b = t;
            bc++;
        }
        else if (b == t)
        {
            bc++;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (ac != bc)
        cout << "NO" << endl;
    else
        cout << "YES" << endl
             << a << " " << b << endl;
    return 0;
}