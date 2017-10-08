#include <iostream>
#include <type_traits>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p = n / 2;
    for (; p > 1; p--)
    {
        if (gcd(p, n - p) == 1)
            break;
    }
    cout << p << " " << n - p << endl;
    return 0;
}