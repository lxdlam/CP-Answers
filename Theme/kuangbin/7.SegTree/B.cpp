#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.2.0"
// Useful Marcos
//====================START=====================
// Compile use C++11 and above
#ifdef LOCAL
#define debug(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define MSG cout << "Finished" << endl
#else
#define debug(args...)
#define MSG
#endif
#if __cplusplus >= 201703L
template <typename... Args>
void readln(Args &... args)
{
    ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
#elif __cplusplus >= 201103L
void readln()
{
}
template <typename T, typename... Args>
void readln(T &a, Args &... args)
{
    cin >> a;
    readln(args...);
}
void writeln()
{
    cout << endl;
}
template <typename T, typename... Args>
void writeln(T a, Args... args)
{
    cout << a << " ";
    writeln(args...);
}
#endif
#if __cplusplus >= 201103L
#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)
#else
#define FOR(_i, _begin, _end) for (int _i = (int)_begin; _i < (int)_end; _i++)
#define FORR(_i, _begin, _end) for (int _i = (int)_begin; _i > (int)_end; _i--)
#define nullptr NULL
#endif
#if __cplusplus >= 201103L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : _name)        \
        cin >> i;
#else
#define VIS(_kind, _name, _size)    \
    vector<_kind> _name;            \
    _name.resize(_size);            \
    for (int i = 0; i < _size; i++) \
        cin >> _name[i];
#endif
// alias
#define mp make_pair
#define pb push_back
#define eb emplace_back
// Swap max/min
template <typename T>
bool smax(T &a, const T &b)
{
    if (a > b)
        return false;
    a = b;
    return true;
}
template <typename T>
bool smin(T &a, const T &b)
{
    if (a < b)
        return false;
    a = b;
    return true;
}
// ceil divide
template <typename T>
T cd(T a, T b)
{
    return (a + b - 1) / b;
}
// min exchange
template <typename T>
bool se(T &a, T &b)
{
    if (a < b)
        return false;
    swap(a, b);
    return true;
}
// A better MAX choice
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
template <typename T>
class SegTree
{
  private:
    size_t size;
    vector<T> data;
    vector<T> flag;  // lazy flag, the current node has been updated but its children haven't
    vector<T> *base; // Avoid copy

    void pushup(int pos)
    {
        data[pos] = max(data[pos << 1], data[pos << 1 | 1]);
    }

    void pushdown(int pos, int lcnt, int rcnt)
    {
        if (flag[pos])
        {
            flag[pos << 1] += flag[pos];
            flag[pos << 1 | 1] += flag[pos];
            data[pos << 1] += flag[pos] * lcnt;
            data[pos << 1 | 1] += flag[pos] * rcnt;
            flag[pos] = 0;
        }
    }

    int calSize(int num)
    {
        int i = 1, j = num;
        while ((j >>= 1) || (i < num))
            i <<= 1;
        return i * 2;
    }

    void build(int l, int r, int cur)
    {
        if (l == r)
        {
            data[cur] = (*base)[l - 1];
            return;
        }

        int m = ((r - l) >> 1) + l;
        build(l, m, cur << 1);
        build(m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    void update(int pos, T val, int l, int r, int cur)
    {
        if (l == r)
        {
            data[cur] = val;
            return;
        }

        int m = ((r - l) >> 1) + l;

        // if mixed
        // pushdown(cur, m - l + 1, r - m);

        if (pos <= m)
            update(pos, val, l, m, cur << 1);
        else
            update(pos, val, m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    void update(int ul, int ur, T val, int l, int r, int cur)
    {
        if (ul <= l && r <= ur)
        {
            data[cur] += val * (r - l + 1);
            flag[cur] += val;
            return;
        }

        int m = ((r - l) >> 1) + l;
        pushdown(cur, m - l + 1, r - m);

        if (ul <= m)
            update(ul, ur, val, l, m, cur << 1);
        if (ur > m)
            update(ul, ur, val, m + 1, r, cur << 1 | 1);
        pushup(cur);
    }

    T query(int ql, int qr, int l, int r, int cur)
    {
        if (ql <= l && r <= qr)
            return data[cur];

        int m = ((r - l) >> 1) + l;
        pushdown(cur, m - l + 1, r - m);

        T ans = 0;
        if (ql <= m)
            smax(ans, query(ql, qr, l, m, cur << 1));
        if (qr > m)
            smax(ans, query(ql, qr, m + 1, r, cur << 1 | 1));
        return ans;
    }

  public:
    void build(vector<T> v)
    {
        size = v.size();
        data.clear();
        flag.clear();
        data.resize(calSize(size));
        flag.resize(calSize(size));
        base = &v;
        build(1, size, 1);
    }

    void update(int pos, T val)
    {
        update(pos, val, 1, size, 1);
    }

    void update(int ul, int ur, T val)
    {
        update(ul, ur, val, 1, size, 1);
    }

    T query(int l, int r)
    {
        return query(l, r, 1, size, 1);
    }
};

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int n, m, l, r;
    string op;
    while (cin >> n >> m)
    {
        VIS(int, v, n);
        SegTree<int> st;
        st.build(v);
        while (m--)
        {
            readln(op, l, r);
            if (op == "Q")
                cout << st.query(l, r) << endl;
            else
                st.update(l, r);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    clock_t _begin = clock();
#endif

    build();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)(clock() - _begin) * 1000 / CLOCKS_PER_SEC << "ms." << endl;
#endif

    return 0;
}