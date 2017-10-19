#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l = 1, r = 1e6, res = 0;
    int mid;
    string token;
    int count = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        cout << mid << endl;
        cin >> token;
        if (token == ">=")
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << "! " << res << endl;
    return 0;
}