/*
洛谷 P3367 【模板】并查集
算法：并查集
完全就是考核并查集基础操作，简单题
*/

#include <iostream>
#include "UF.h"

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int z, p, q;
    UFO ufo(n);
    while (m--)
    {
        cin >> z >> p >> q;
        if (z == 1)
        {
            if (!ufo.connected(p - 1, q - 1))
                ufo.Union(p - 1, q - 1);
        }
        else if (z == 2)
        {
            if (ufo.connected(p - 1, q - 1))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    return 0;
}