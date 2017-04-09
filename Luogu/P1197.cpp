/*
洛谷 P1197 星球大战
算法：并查集
出处：JSOI2008
*/
#include <iostream>
#include "UF.h"
#include <vector>

struct Planets
{
    int a;
    int b;
};

using namespace std;

int main()
{
    int n, m, k, tmp;
    vector<Planets> vp;
    vector<int> vd;
    cin >> n >> m;
    UFO ufo(n);
    while (m--)
    {
        Planets planet;
        cin >> planet.a >> planet.b;
        vp.push_back(planet);
    }
    cin >> k;
    while (k--)
    {
        cin >> tmp;
        vd.push_back(tmp);
    }
    for (int i = vd.size() - 1; i >= 0; i--)
    {
        tmp = vd[i];
        for (int j = 0; j < vp.size(); j++)
        {
            if (vp[j].a == tmp || vp[j].b == tmp)
                continue;
            if (!ufo.connected(vp[j].a - 1, vp[j].b - 1))
                ufo.Union(vp[j].a - 1, vp[j].b - 1);
        }
        cout << ufo.getCount() << endl;
    }
    return 0;
}