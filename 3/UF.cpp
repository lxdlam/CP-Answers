#include <iostream>
#include "UF.h"

using namespace std;

int main()
{
    int n;
    int p, q;
    cin >> n;
    UF uf(n);
    UFO ufo(n);
    while (cin >> p >> q)
    {
        if (!uf.connected(p, q))
            uf.Union(p, q);
        if (!ufo.connected(p, q))
            ufo.Union(p, q);
    }
    cout << "Using quick-find algorithm: " << uf.getCount() << endl;
    cout << "Using optimized algorithm: " << ufo.getCount() << endl;
    return 0;
}