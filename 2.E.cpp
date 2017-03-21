#include <iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (n >= m * m / 4)
            cout << 'T' << endl;
        else
            cout << 'F' << endl;
    }
    return 0;
}