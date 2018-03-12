#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int l, r;
    while (cin >> n >> m)
    {
        UF uf(n);
        while (m--)
        {
            cin >> l >> r;
            uf.Union(l - 1, r - 1);
        }
        cout << uf.getCount() - 1 << endl;
    }

    return 0;
}