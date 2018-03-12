#include <iostream>
#include <vector>

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, t, n, l, r;
    string op;
    vi v;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {
        v.clear();
        cout << "Case " << kase << ":" << endl;
        cin >> n;
        for (int i = 0; i < n + 1; i++)
            v.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            update(v, i, t);
        }
        while (cin >> op && op != "End")
        {
            cin >> l >> r;
            if (op == "Query")
                cout << getVal(v, r) - getVal(v, l - 1) << endl;
            else if (op == "Add")
                update(v, l, r);
            else if (op == "Sub")
                update(v, l, -r);
        }
    }
    return 0;
}