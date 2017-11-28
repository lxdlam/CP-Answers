#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h = 0, t, T;
    cin >> T;
    while (T--)
    {
        cin >> t;
        h = max(h, t);
    }
    cout << (h ^ t) << endl;

    return 0;
}