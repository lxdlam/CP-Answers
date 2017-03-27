//A really simple but not effective union-find class
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