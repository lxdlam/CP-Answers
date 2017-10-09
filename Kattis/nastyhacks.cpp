#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int a, b, c;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        b -= c;
        if (a > b)
        {
            cout << "do not advertise" << endl;
        }
        else if (a == b)
        {
            cout << "does not matter" << endl;
        }
        else
            cout << "advertise" << endl;
    }
    return 0;
}