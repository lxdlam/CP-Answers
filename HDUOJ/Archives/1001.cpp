#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    while (cin >> t)
        cout << (t * (t + 1) / 2) << "\n\n";
    return 0;
}