#include <iostream>
#include "UF.h"
#include <vector>
#include <algorithm>
#include <cstdlib>

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
        ans = 2147483646;
        if (!n)
            break;
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
            UF uf(n);
            k = n - 1;
            ans = min(ans, temp);
        }
        cout << ans << endl;
    }
    return 0;
}

bool comp(const Road &a, const Road &b)
{
    return a.money < b.money;
}