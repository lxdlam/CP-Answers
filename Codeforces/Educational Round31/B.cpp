#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    int sum = 0, a;
    cin >> n >> x;
    while (n--)
    {
        cin >> a;
        sum += a + (n == 0 ? 0 : 1);
    }
    if (sum == x || sum == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}