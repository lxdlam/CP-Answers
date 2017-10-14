#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

inline int lowbit(int k)
{
    return k & -k;
}

void update(vi &v, int pos, int val)
{
    int len = v.size();
    while (pos < len)
    {
        //change behavior here
        v[pos] += val;
        pos += lowbit(pos);
    }
}

int getVal(vi &v, int pos)
{
    int res = 0;
    while (pos)
    {
        res += v[pos];
        pos -= lowbit(pos);
    }
    return res;
}