#include <bits/stdc++.h>

#define FOR(_i, _s, _e) for (int _i = _s; _i < _e; _i++)
#if __cpluscplus > 201103L
#define FORE(_c) for (auto i : _c)
#define FORER(_c) for (auto &i : _c)
#else
#define FORE(_c)
#define FORER(_c)
#endif
#if __cpluscplus > 201402L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : v)            \
        cin >> i;
#elif __cpluscplus > 201103L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name;         \
    _name.resize(_size);         \
    for (auto &i : v)            \
        cin >> i;
#else
#define VIS(_kind, _name, _size)    \
    vector<_kind> _name;            \
    _name.resize(_size);            \
    for (int i = 0; i < _size; i++) \
        cin >> v[i];
#endif

#define DEBUG(a) cout << #a << ": " << a << endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

struct SegTree
{
    // inner struct
    struct Node
    {
        int val;
    };

    vector<Node> tree;
    int size;

    SegTree() : size(0)
    {
        tree.clear();
    }

    void init(int size)
    {
        this->size = size;
        tree.resize(size << 2);
    }

    void clear()
    {
        tree.clear();
        size = 0;
    }

    void build(const vector<int> &v)
    {
        build(0, 0, size - 1, v);
    }

    void update(int index, int val)
    {
        update(0, 0, size - 1, index - 1, val);
    }

    int query(int l, int r)
    {
        return query(0, 0, size - 1, l - 1, r - 1);
    }

  private:
    // 0-index
    inline int left(int i) { return (i << 1) + 1; }
    inline int right(int i) { return (i << 1) + 2; }

    void build(int node, int l, int r, const vector<int> &v)
    {
        if (l == r)
            tree[node].val = v[l];
        else
        {
            int mid = (l + r) >> 1;
            build(left(node), l, mid, v);
            build(right(node), mid + 1, r, v);
            tree[node].val = tree[left(node)].val + tree[right(node)].val;
        }
    }

    void update(int node, int l, int r, int index, int val)
    {
        if (l == r)
            tree[node].val += val;
        else
        {
            int mid = (l + r) >> 1;
            if (l <= index && index <= mid)
                update(left(node), l, mid, index, val);
            else
                update(right(node), mid + 1, r, index, val);
            tree[node].val = tree[left(node)].val + tree[right(node)].val;
        }
    }

    // start and end is current section, l and r is our expect section
    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return 0;
        if (l <= start && end <= r)
            return tree[node].val;
        int mid = (start + end) >> 1;
        int lv = query(left(node), start, mid, l, r);
        int rv = query(right(node), mid + 1, end, l, r);
        return lv + rv;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, i, j;
    string op;
    SegTree st;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << endl;
        cin >> n;
        VIS(int, v, n);
        st.clear();
        st.init(n);
        st.build(v);
        while (cin >> op && op != "End")
        {
            cin >> i >> j;
            if (op == "Add")
                st.update(i, j);
            else if (op == "Sub")
                st.update(i, -j);
            else if (op == "Query")
                cout << st.query(i, j) << endl;
        }
    }

    return 0;
}