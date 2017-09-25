#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int count = 0;
    int a, b;
    cin >> a >> b;
    while (a <= b)
    {
        count++;
        a *= 3;
        b *= 2;
    }
    cout << count << endl;
    return 0;
}