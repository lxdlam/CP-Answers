#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long t;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> t;
        if (t == 1 || t == 2 || t == 3 || t == 5 || t == 7 || t == 11)
            cout << -1 << endl;
        else if (t == 4 || t == 6 || t == 9)
            cout << 1 << endl;
        else if (t % 2 == 0)
            cout << (t / 4) << endl;
        else
            cout << t / 4 - 1 << endl;
    }
    return 0;
}