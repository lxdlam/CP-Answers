#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int tank = b;
    int l = f, r = a - f;
    int t = 0;
    while (true)
    {
        // 0 -> a
        // arrive f
        tank -= l;
        if (tank < 0)
        {
            t = -1;
            break;
        }
        // refuel
        if (k == 1)
        {
            if (b < r)
                t = -1;
            else if (tank < r)
                t++;
            break;
        }
        if (tank < 2 * r)
        {
            tank = b;
            t++;
        }
        // arrive a
        tank -= r;
        k--;

        // a -> 0
        tank -= r;
        if (tank < 0)
        {
            t = -1;
            break;
        }
        if (k == 1)
        {
            if (b < l)
                t = -1;
            else if (tank < l)
                t++;
            break;
        }
        // refuel
        if (tank < 2 * l)
        {
            tank = b;
            t++;
        }
        // arrive 0
        tank -= l;
        k--;
    }
    cout << t << endl;
    return 0;
}