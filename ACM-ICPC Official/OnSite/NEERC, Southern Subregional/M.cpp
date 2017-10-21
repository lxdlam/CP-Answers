#include <iostream>

using namespace std;

inline int abs(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
        x1--;
    if (y1 == y2)
        y1--;
    cout << 2 * (abs(x1 - x2) + abs(y1 - y2) + 2) << endl;
    return 0;
}