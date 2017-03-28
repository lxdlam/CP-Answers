#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "UF.h"

using namespace std;

int main()
{
    int p, q, size;
    bool isExit = false;
    bool isRing = false;
    int count = 0;
    vector<Number> v;
    set<int> s;
    while (true)
    {
        count = 0;
        isRing = false;
        size = 0;
        while (cin >> p >> q)
        {
            if (p == -1)
            {
                isExit = true;
                break;
            }
            if (p == 0)
                break;
            s.insert(p - 1);
            s.insert(q - 1);
            Number num;
            num.p = p;
            num.q = q;
            size = max(size, max(p, q));
            v.push_back(num);
        }
        if (isExit)
            break;
        UFO ufo(size);
        for (int i = 0; i < v.size(); i++)
        {
            if (ufo.connected(v[i].p - 1, v[i].q - 1))
                isRing = true;
            ufo.Union(v[i].p - 1, v[i].q - 1);
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); it++)
            if (ufo.find(*it) == *it)
                count++;
        if (isRing)
            cout << "No" << endl;
        else if (count == 1 || (p == 0 && count == 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        v.clear();
        s.clear();
    }
    return 0;
}