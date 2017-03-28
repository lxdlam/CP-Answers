#include <iostream>
#include "UF.h"
#include <vector>
#include <algorithm>

using namespace std;

struct Road
{
    int a;
    int b;
    int money;
};

bool comp(const Road &, const Road &);

int main()
{
    int n, m, k;
    int p, q, r;
    int ans, temp;
    vector<Road> v;
    while (cin >> n)
    {
        v.clear();
        ans = 0;
        if (!n)
            break;
        UFO ufo(n);
        m = n * (n - 1) / 2;
        while (m--)
        {
            cin >> p >> q >> r;
            Road road;
            road.a = p;
            road.b = q;
            road.money = r;
            v.push_back(road);
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); i++)
        {
            if (!ufo.connected(v[i].a - 1, v[i].b - 1))
            {
                ufo.Union(v[i].a - 1, v[i].b - 1);
                ans += v[i].money;
            }
            if (!ufo.getCount())
                break;
        }
        cout << ans << endl;
    }
    return 0;
}

bool comp(const Road &a, const Road &b)
{
    return a.money < b.money;
}