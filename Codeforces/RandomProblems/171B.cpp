#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    cout << 6 * a * (a - 1) + 1 << endl;

    return 0;
}