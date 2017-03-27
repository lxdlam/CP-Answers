#include <iostream>
#include <cstdlib>

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

using namespace std;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 4;
const int RIGHT = 8;

const int Blocks[11] = {UP | LEFT, UP | RIGHT, LEFT | DOWN, RIGHT | DOWN, UP | DOWN, LEFT | RIGHT, UP | LEFT | RIGHT, LEFT | UP | DOWN, DOWN | LEFT | RIGHT, RIGHT | UP | DOWN, UP | DOWN | LEFT | RIGHT};

int Bits(int, int);

int main()
{
    int size;
    int m, n;
    while (cin >> m >> n)
    {
        cin.get();
        if (m == -1)
            break;
        UF uf(n * m);
        int *temp = new int[n * m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                temp[i * n + j] = cin.get() - 'A';
            cin.get();
        }
        for (int i = 0; i < m * n; i++)
        {
            if (i + n < m * n && Bits(Blocks[temp[i]], 2) && Bits(Blocks[temp[i + n]], 1) && !uf.connected(i, i + n))
                uf.Union(i, i + n);
            if (i % n + 1 < n && Bits(Blocks[temp[i]], 4) && Bits(Blocks[temp[i + 1]], 3) && !uf.connected(i, i + 1))
                uf.Union(i, i + 1);
        }
        cout << uf.getCount() << endl;
        cin.get();
    }
    return 0;
}

int Bits(int n, int m)
{
    return (n >> (m - 1)) & 1;
}