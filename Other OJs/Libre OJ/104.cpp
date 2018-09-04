#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.4.1"
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
#define all(x) (x).begin(), (x).end()
#define tcase() \
    int T;      \
    cin >> T;   \
    FOR(kase, 1, T + 1)
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
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
struct Splay
{
    static const int SIZE = 1e5 + 10;
    int rt;          // root
    int tot;         // total nodes
    int fa[SIZE];    // father of node i
    int ch[SIZE][2]; // child of node i, 0 is left
    int val[SIZE];   // value of node i
    int cnt[SIZE];   // Count of the number of val i
    int sz[SIZE];    // size of subtree of node i

    void mt(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }

    bool get(int x)
    {
        return x == ch[fa[x]][1];
    }

    void reset(int x)
    {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }

    void rotate(int x)
    {
        int y = fa[x], z = fa[y], chk = get(x);

        ch[y][chk] = ch[x][chk ^ 1];
        fa[ch[x][chk ^ 1]] = y;

        ch[x][chk ^ 1] = y;
        fa[y] = x;

        fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;

        mt(x);
        mt(y);
    }

    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);
        rt = x;
    }

    void insert(int k)
    {
        if (!rt)
        {
            val[++tot] = k;
            cnt[tot]++;
            rt = tot;
            mt(rt);
            return;
        }

        int cur = rt, f = 0;
        while (true)
        {
            if (val[cur] == k)
            {
                cnt[cur]++;
                mt(cur);
                mt(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur] < k];
            if (!cur)
            {
                val[++tot] = k;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f] < k] = tot;
                mt(tot);
                mt(f);
                splay(tot);
                break;
            }
        }
    }

    void init()
    {
        tot = rt = 0;
    }

    int rk(int k)
    {
        int res = 0, cur = rt;
        while (true)
        {
            if (k < val[cur])
                cur = ch[cur][0];
            else
            {
                res += sz[ch[cur][0]];
                if (k == val[cur])
                {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k)
    {
        int cur = rt;
        while (true)
        {
            if (ch[cur][0] && k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else
            {
                k -= cnt[cur] + sz[ch[cur][0]];
                if (k <= 0)
                    return val[cur];
                cur = ch[cur][1];
            }
        }
    }

    int pred()
    {
        int cur = ch[rt][0];
        while (ch[cur][1])
            cur = ch[cur][1];
        return cur;
    }

    int succ()
    {
        int cur = ch[rt][1];
        while (ch[cur][0])
            cur = ch[cur][0];
        return cur;
    }

    void erase(int k)
    {
        rk(k);
        if (cnt[rt] > 1)
        {
            cnt[rt]--;
            mt(rt);
            return;
        }
        if (!ch[rt][0] && !ch[rt][1])
        {
            reset(rt);
            rt = 0;
            return;
        }
        if (!ch[rt][0])
        {
            int cur = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        if (!ch[rt][1])
        {
            int cur = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            reset(cur);
            return;
        }
        int x = pred(), cur = rt;
        splay(x);
        fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1];
        reset(cur);
        mt(rt);
    }

} sp;

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int n;
    cin >> n;
    int op, x;
    sp.init();
    while (n--)
    {
        cin >> op >> x;
        if (op == 1)
            sp.insert(x);
        else if (op == 2)
            sp.erase(x);
        else if (op == 3)
            cout << sp.rk(x) << '\n';
        else if (op == 4)
            cout << sp.kth(x) << '\n';
        else if (op == 5)
        {
            sp.insert(x);
            cout << sp.val[sp.pred()] << '\n';
            sp.erase(x);
        }
        else if (op == 6)
        {
            sp.insert(x);
            cout << sp.val[sp.succ()] << '\n';
            sp.erase(x);
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