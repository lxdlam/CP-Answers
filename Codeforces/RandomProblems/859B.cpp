#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b, n;
    cin >> n;
    a = ceil(sqrt(n));
    b = ceil(n / a);
    cout << 2 * (a + b) << endl;
    return 0;
}