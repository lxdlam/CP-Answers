#include <iostream>

using namespace std;

const int aday = 86400;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, a;
    cin >> n >> t;
    int day = 0;
    while (n-- && t > 0)
    {
        day++;
        cin >> a;
        if (a < aday)
            t -= (aday - a);
    }
    cout << day << endl;
}