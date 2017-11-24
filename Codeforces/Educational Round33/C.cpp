#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

class UF
{
  public:
    UF(int n)
    {
        count = length = n;
        id.resize(n);
        for (int i = 0; i < length; i++)
            id[i] = i;
        sz.resize(n);
        for (int i = 0; i < length; i++)
            sz[i] = 1;
    }

    int getCount()
    {
        return count;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    int find(int p)
    {
        int k = p, j;
        while (p != id[p])
            p = id[p];
        while (k != p)
        {
            j = id[k];
            id[k] = p;
            k = j;
        }
        return p;
    }

    void Union(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        if (sz[pRoot] < sz[qRoot])
        {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        }
        else
        {
            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        count--;
    }

  private:
    int count;
    vector<int> id;
    vector<int> sz;
    int length;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int p, q;
    int x;
    cin >> n >> m;
    ll res = 0;

    vi ans(n + 1, INT_MAX);
    vi c(n + 1);
    UF uf(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    while (m--)
    {
        cin >> p >> q;
        uf.Union(p, q);
    }

    for (int i = 1; i <= n; i++)
    {
        x = uf.find(i);
        ans[x] = min(ans[x], c[i]);
    }

    for (int i = 1; i <= n; i++)
        if (ans[i] != INT_MAX)
            res += ans[i];

    cout << res << endl;

    return 0;
}