#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, f, k, l, r;
    long long tank = 0, res = 0;
    cin >> a >> b >> f >> k;
    tank = b;
    l = f;
    r = 2 * a - 2 * f;
    while (true)
    {
        tank = tank - l;
        if (tank < 0)
            break;
        if (tank >= r)
            tank = tank - r;
        else
        {
            res++;
            tank = b - r;
        }
        if (--k == 0)
            break;
        if (tank < 0)
            break;
        if (tank >= 2 * l)
            tank = tank - l;
        else
        {
            tank = b - l;
            res++;
        }
        if (tank < 0)
            break;
        if (--k == 0)
            break;
    }
    if (k != 0)
        cout << -1 << endl;
    else if (tank > l)
        cout << res - 1 << endl;
    else
        cout << res << endl;
    return 0;
}