// Source: https://open.kattis.com/problems/oddities
// From: 2013 ACM-ICPC North American Qualifier

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, t;
    cin >> T;
    while (T--)
    {
        cin >> t;
        if (t % 2 == 0)
        {
            cout << t << " is even" << endl;
        }
        else
            cout << t << " is odd" << endl;
    }
    return 0;
}