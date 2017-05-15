#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UFO
{
  public:
    UFO(int n)
    {
        count = length = n;
        id = new int[n];
        for (int i = 0; i < length; i++)
            id[i] = i;
        sz = new int[n];
        for (int i = 0; i < length; i++)
            sz[i] = 1;
    }

    ~UFO()
    {
        delete[] id;
        delete[] sz;
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
    int *id int *sz;
    int length;
};

class Node
{
  public:
    int a;
    int b;
    int money;

    Node(int a, int b, int money)
    {
        this->a = a;
        this->b = b;
        this->money = money;
    }

    bool operator<(const Node &n) const
    {
        return money < n.money;
    }
};

int main()
{
    int n, m;
    int i, j, k;
    int count;
    vector<Node> v;
    while (cin >> n >> m && n != 0)
    {
        v.clear();
        count = 0;
        UFO ufo(n);
        while (m--)
        {
            cin >> i >> j >> k;
            Node n(i, j, k);
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        for (vector<Node>::iterator it = v.begin(); it != v.end(); it++)
        {
            if (ufo.getCount() <= 1)
                break;
            if (!ufo.connected(it->a - 1, it->b - 1))
            {
                ufo.Union(it->a - 1, it->b - 1);
                count += it->money;
            }
        }
        cout << count << endl;
    }
    return 0;
}