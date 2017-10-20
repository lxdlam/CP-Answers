#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l = 1, res = 0, mid, token, r;
    cin >> r;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        cout << "Q " << mid << endl;
        cin >> token;
        if (token == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << "A " << l << endl;
    return 0;
}