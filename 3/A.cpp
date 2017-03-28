#include <iostream>
#include "UF.h"

using namespace std;

int main()
{
    int n, m;
    int p, q;
    int count;
    while (cin >> n >> m)
    {
        if (!n)
            break;
        UF uf(n);
        while (m--)
        {
            cin >> p >> q;
            if (!uf.connected(p - 1, q - 1))
                uf.Union(p - 1, q - 1);
        }
        cout << uf.getCount() - 1 << endl;
    }
    return 0;
}