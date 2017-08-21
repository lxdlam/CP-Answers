#include <cstdio>
#include <string>

using namespace std;

class UF
{
  public:
    UF(int n)
    {
        count = length = n;
        id = new int[n];
        for (int i = 0; i < length; i++)
            id[i] = i;
        sz = new int[n];
        for (int i = 0; i < length; i++)
            sz[i] = 1;
    }

    ~UF()
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
    int *id;
    int *sz;
    int length;
};

long long pow(int num, int expr)
{
    long long res = 1;
    while (expr--)
        res *= num;
    return res;
}

int main()
{
    int n, m, op, u, v;
    long long res = 0;
    scanf("%d%d", &n, &m);
    UF uf(n);
    string ans = "";
    while (m--)
    {
        scanf("%d%d%d", &op, &u, &v);
        switch (op)
        {
        case 0:
            uf.Union(u, v);
            break;
        case 1:
            if (uf.connected(u, v))
                ans += "1";
            else
                ans += "0";
            break;
        }
    }
    for (int i = 0; i < ans.size(); i++)
        res += (ans[i] - '0') ? pow(2, ans.size() - i - 1) : 0;
    printf("%lld\n", res % 998244353);
    return 0;
}