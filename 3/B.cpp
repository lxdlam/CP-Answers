#include <iostream>
#include "UF.h"

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, m;
    int p, q;
    while (t--)
    {
        cin >> n >> m;
        UF uf(n);
        while (m--)
        {
            cin >> p >> q;
            if (!uf.connected(p - 1, q - 1))
                uf.Union(p - 1, q - 1);
        }
        cout << uf.getCount() << endl;
        cin.get();
    }
    return 0;
}