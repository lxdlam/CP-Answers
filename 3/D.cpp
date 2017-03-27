#include <iostream>
#include "UF.h"
#include <algorithm>
#include <vector>

struct Number
{
    int p;
    int q;
};

using namespace std;

int main()
{
    int p, q, size;
    bool isExit = false;
    vector<Number> v;
    while (true)
    {
        while (cin >> p >> q)
        {
            if (p == -1)
            {
                isExit = true;
                break;
            }
            else if (!p)
                break;
            Number num;
            num.p = p;
            num.q = q;
            v.push_back(num);
            size = max(p, q);
        }
        if (isExit)
            break;
        UF uf(size);
        for (int i = 0; i < v.size(); i++)
            if (!uf.connected(v[i].p - 1, v[i].q - 1))
                uf.Union(v[i].p - 1, v[i].q - 1);
        cout << (uf.getCount() - size + 1 < 0 ? "Yes" : "No") << endl;
        cin.get();
    }
    return 0;
}