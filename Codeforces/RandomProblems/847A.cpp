#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> h, t;
    int n, a, b;
    cin >> n;
    UF uf(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a != 0)
            uf.Union(a - 1, i);
        else
            h.emplace_back(i);
        if (b != 0)
            uf.Union(i, b - 1);
        else
            t.emplace_back(i);
        ans.emplace_back(make_pair(a, b));
    }
    for (int i = 0; i < t.size() - 1; i++)
    {
        for (int j = 0; j < h.size(); j++)
        {
            if (h[j] != -1 && !uf.connected(t[i], h[j]))
            {
                ans[t[i]] = make_pair(ans[t[i]].first, h[j] + 1);
                ans[h[j]] = make_pair(t[i] + 1, ans[h[j]].second);
                uf.Union(t[i], h[j]);
                h[j] = -1;
                break;
            }
        }
    }
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}