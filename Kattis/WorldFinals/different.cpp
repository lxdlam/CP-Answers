#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    while (cin >> a >> b)
    {
        if (a > b)
            cout << a - b << endl;
        else
            cout << b - a << endl;
    }

    return 0;
}