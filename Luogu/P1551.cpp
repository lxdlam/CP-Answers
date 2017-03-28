/*
洛谷 P1551 亲戚
算法：并查集
输入亲戚为触点，之后询问是否是同一连通分量
结果：AC
*/

#include <iostream>
#include "UF.h"

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int p, q;
    UFO ufo(n);
    while (a--)
    {
        cin >> p >> q;
        if (!ufo.connected(p - 1, q - 1))
            ufo.Union(p - 1, q - 1);
    }
    while (b--)
    {
        cin >> p >> q;
        if (ufo.connected(p - 1, q - 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}