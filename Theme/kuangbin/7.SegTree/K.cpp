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
const int SIZE = 1e5 + 10;
const ll MOD = 1e4 + 7;

ll s1[SIZE << 2], s2[SIZE << 2], s3[SIZE << 2];
ll add[SIZE << 2], mul[SIZE << 2], cha[SIZE << 2];

ll fp(ll base, ll expr, ll mod = 1e4 + 7)
{
    ll ans = 1;
    base %= mod;
    while (expr)
    {
        if (expr & 1LL)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        expr >>= 1LL;
    }
    return ans % mod;
}

void pushup(int pos)
{
    s1[pos] = (s1[pos << 1] + s1[pos << 1 | 1]) % MOD;
    s2[pos] = (s2[pos << 1] + s2[pos << 1 | 1]) % MOD;
    s3[pos] = (s3[pos << 1] + s3[pos << 1 | 1]) % MOD;
}

void pushdown(int pos, int lt, int rt)
{
    if (cha[pos])
    {
        cha[pos << 1] = cha[pos << 1 | 1] = cha[pos];
        add[pos << 1] = add[pos << 1 | 1] = 0;
        mul[pos << 1] = mul[pos << 1 | 1] = 1;

        s1[pos << 1] = ((lt % MOD) * (cha[pos] % MOD)) % MOD;
        s1[pos << 1 | 1] = ((rt % MOD) * (cha[pos] % MOD)) % MOD;
        s2[pos << 1] = ((lt % MOD) * fp(cha[pos], 2)) % MOD;
        s2[pos << 1 | 1] = ((rt % MOD) * fp(cha[pos], 2)) % MOD;
        s3[pos << 1] = ((lt % MOD) * fp(cha[pos], 3)) % MOD;
        s3[pos << 1 | 1] = ((rt % MOD) * fp(cha[pos], 3)) % MOD;

        cha[pos] = 0;
    }
    if (mul[pos] != 1)
    {
        mul[pos << 1] = (mul[pos << 1] * mul[pos]) % MOD;
        mul[pos << 1 | 1] = (mul[pos << 1 | 1] * mul[pos]) % MOD;
        if (add[pos << 1])
            add[pos << 1] = (add[pos << 1] * mul[pos]) % MOD;
        if (add[pos << 1 | 1])
            add[pos << 1 | 1] = (add[pos << 1 | 1] * mul[pos]) % MOD;

        s1[pos << 1] = (s1[pos << 1] * mul[pos]) % MOD;
        s1[pos << 1 | 1] = (s1[pos << 1 | 1] * mul[pos]) % MOD;
        s2[pos << 1] = (s2[pos << 1] * fp(mul[pos], 2)) % MOD;
        s2[pos << 1 | 1] = (s2[pos << 1 | 1] * fp(mul[pos], 2)) % MOD;
        s3[pos << 1] = (s3[pos << 1] * fp(mul[pos], 3)) % MOD;
        s3[pos << 1 | 1] = (s3[pos << 1 | 1] * fp(mul[pos], 3)) % MOD;

        mul[pos] = 1;
    }
    if (add[pos])
    {
        add[pos << 1] = (add[pos << 1] + add[pos]) % MOD;
        add[pos << 1 | 1] = (add[pos << 1 | 1] + add[pos]) % MOD;

        s3[pos << 1] = (s3[pos << 1] + lt * fp(add[pos], 3) % MOD + 3 * (add[pos] * s2[pos << 1]) % MOD + 3 * (fp(add[pos], 2) * s1[pos << 1]) % MOD) % MOD;
        s3[pos << 1 | 1] = (s3[pos << 1 | 1] + rt * fp(add[pos], 3) % MOD + 3 * (add[pos] * s2[pos << 1 | 1]) % MOD + 3 * (fp(add[pos], 2) * s1[pos << 1 | 1]) % MOD) % MOD;

        s2[pos << 1] = (s2[pos << 1] + 2 * (add[pos] * s1[pos << 1]) % MOD + (lt * fp(add[pos], 2)) % MOD) % MOD;
        s2[pos << 1 | 1] = (s2[pos << 1 | 1] + 2 * (add[pos] * s1[pos << 1 | 1]) % MOD + (rt * fp(add[pos], 2)) % MOD) % MOD;

        s1[pos << 1] = (s1[pos << 1] + lt * add[pos]) % MOD;
        s1[pos << 1 | 1] = (s1[pos << 1 | 1] + rt * add[pos]) % MOD;

        add[pos] = 0;
    }
}

void update(int ul, int ur, int type, ll val, int l, int r, int cur)
{
    if (ul <= l && r <= ur)
    {
        if (type == 3)
        {
            add[cur] = 0;
            mul[cur] = 1;
            cha[cur] = val;
            s1[cur] = ((r - l + 1) * val) % MOD;
            s2[cur] = ((r - l + 1) * fp(val, 2)) % MOD;
            s3[cur] = ((r - l + 1) * fp(val, 3)) % MOD;
        }
        else if (type == 2)
        {
            mul[cur] = (mul[cur] * val) % MOD;
            if (add[cur])
                add[cur] = (add[cur] * val) % MOD;
            s1[cur] = (s1[cur] * val) % MOD;
            s2[cur] = (s2[cur] * fp(val, 2)) % MOD;
            s3[cur] = (s3[cur] * fp(val, 3)) % MOD;
        }
        else
        {
            add[cur] = (add[cur] + val) % MOD;
            s3[cur] = (s3[cur] + (r - l + 1) * fp(val, 3) % MOD + 3 * (val * s2[cur]) % MOD + 3 * (fp(val, 2) * s1[cur]) % MOD) % MOD;
            s2[cur] = (s2[cur] + 2 * (val * s1[cur]) % MOD + ((r - l + 1) * fp(val, 2)) % MOD) % MOD;
            s1[cur] = (s1[cur] + (r - l + 1) * val) % MOD;
        }
        return;
    }

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);
    if (ul <= m)
        update(ul, ur, type, val, l, m, cur << 1);
    if (ur > m)
        update(ul, ur, type, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
}

void build(int l, int r, int cur)
{
    add[cur] = cha[cur] = 0;
    mul[cur] = 1;
    if (l == r)
    {
        s1[cur] = s2[cur] = s3[cur] = 0;
        return;
    }

    int m = ((r - l) >> 1) + l;
    build(l, m, cur << 1);
    build(m + 1, r, cur << 1 | 1);
    pushup(cur);
}

ll query(int ql, int qr, int type, int l, int r, int cur)
{
    if (ql <= l && r <= qr)
    {
        switch (type)
        {
        case 1:
            return s1[cur] % MOD;
        case 2:
            return s2[cur] % MOD;
        case 3:
            return s3[cur] % MOD;
        }
    }

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);
    ll ans = 0;
    if (ql <= m)
        ans = (ans + query(ql, qr, type, l, m, cur << 1)) % MOD;
    if (qr > m)
        ans = (ans + query(ql, qr, type, m + 1, r, cur << 1 | 1)) % MOD;
    return ans % MOD;
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int n, m;
    while (cin >> n >> m && n && m)
    {
        build(1, n, 1);
        ll op, x, y, k;
        while (m--)
        {
            readln(op, x, y, k);
            switch (op)
            {
            case 4:
                cout << query(x, y, k, 1, n, 1) << endl;
                break;
            default:
                update(x, y, op, k, 1, n, 1);
            }
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