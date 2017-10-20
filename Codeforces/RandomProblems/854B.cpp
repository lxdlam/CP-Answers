#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 0 || k == n)
        cout << "0 0" << endl;
    else
    {
        cout << 1 << " ";
        if (k < (n / 3 + 0.5))
            cout << 2 * k << endl;
        else
            cout << n - k << endl;
    }
    return 0;
}