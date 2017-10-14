#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9 + 7;

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
    int n, m;
    string op;
    int x, y, val, l, r;
    cin >> n >> m;
    vector<vi> mat;
    for (int i = 0; i < n; i++)
    {
        vi t;
        for (int j = 0; j < n + 1; j++)
            t.push_back(0);
        mat.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        val = 0;
        cin >> op;
        if (op == "Add")
        {
            cin >> x >> y >> val;
            update(mat[x], y + 1, val);
        }
        else if (op == "Sum")
        {
            cin >> x >> y >> l >> r;
            for (; x <= l; x++)
                val += (getVal(mat[x], r + 1) - getVal(mat[x], y)) % MOD;
            if (val < 0)
                val += MOD;
            cout << val << endl;
        }
    }
    return 0;
}