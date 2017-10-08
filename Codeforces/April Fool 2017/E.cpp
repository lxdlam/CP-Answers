#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = a ^ b, f = c | d, g = b & c, h = a ^ d;
    int aa = e & f, bb = g | h;
    cout << (aa ^ bb) << endl;

    return 0;
}