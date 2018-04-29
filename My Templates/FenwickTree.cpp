#include <bits/stdc++.h>

using namespace std;

template <typename T>
class FenTree
{
  private:
    vector<T> v;
    size_t size;

    inline int lowbit(int k)
    {
        return k & -k;
    }

  public:
    void init(vector<T> base)
    {
        this->size = base.size() + 1;
        v.clear();
        v.resize(size + 1);
        for (int i = 1; i < size; i++)
            this->update(i, base[i - 1]);
    }

    void update(int pos, T val)
    {
        while (pos < size)
        {
            v[pos] += val;
            pos += lowbit(pos);
        }
    }

    T get(int pos)
    {
        T res = 0;
        while (pos)
        {
            res += v[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    T getSeg(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};