/*
洛谷 P1111 修复公路
算法：并查集
简单题，拿到所有数据排一次序，然后一个个塞进去，只要某一组数据后只有一个连通分量那这就是最短时间
相反，走到底连通分量都比1大就说明走不通，输出-1
*/
#include <iostream>
#include <vector>
#include "UF.h"
#include <algorithm>

using namespace std;

struct Road
{
    int x;
    int y;
    int t;
};

bool comp(const Road &, const Road &);

int main()
{
    int x, y, t;
    int n, m;
    int ans = -1;
    vector<Road> v;
    cin >> n >> m;
    UFO ufo(n);
    while (m--)
    {
        cin >> x >> y >> t;
        Road road;
        road.x = x;
        road.y = y;
        road.t = t;
        v.push_back(road);
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        if (!ufo.connected(v[i].x - 1, v[i].y - 1))
            ufo.Union(v[i].x - 1, v[i].y - 1);
        if (ufo.getCount() == 1)
        {
            ans = v[i].t;
            break;
        }
    }
    cout << ans << endl;
}

bool comp(const Road &a, const Road &b)
{
    return a.t < b.t;
}