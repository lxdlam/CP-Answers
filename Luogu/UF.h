//基础并查集定义，非树形结构
class UF
{
  public:
    UF(int N)
    {
        id = new int[N];
        count = N;
        length = N;
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    ~UF()
    {
        delete[] id;
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
        return id[p];
    }

    void Union(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID)
            return;

        for (int i = 0; i < length; i++)
            if (id[i] == pID)
                id[i] = qID;
        count--;
    }

  private:
    int count;
    int *id;
    int length;
};

//最终优化后的并查集
//进行了三个方向的优化：树形结构转化、加权、路径压缩
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
    int *id;
    int *sz;
    int length;
};