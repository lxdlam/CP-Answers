#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    long long k;
    cin >> n >> k;
    int big = 0, p = 0;
    while (n--)
    {
        cin >> t;
        if (big <= 0)
            p = 0;
        else if (big > t)
            p++;
        else
            p = 1;
        big = max(t, big);
        if (p == k)
            break;
    }
    cout << big << endl;
    return 0;
}