#include <iostream>
#include <string>
#include <map>
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
    map<string, int> m;
    int i = 0, T, op;
    string a, b;
    cin >> T;
    UF uf(T);
    while (T--)
    {
        cin >> op >> a >> b;
        switch (op)
        {
        case 0:
            if (m.count(a) == 0)
            {
                m[a] = i;
                i++;
            }
            if (m.count(b) == 0)
            {
                m[b] = i;
                i++;
            }
            uf.Union(m[a], m[b]);
            break;
        case 1:
            if (uf.connected(m[a], m[b]))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}