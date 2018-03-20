#include <bits/stdc++.h>

using namespace std;

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
#define FOR(_i, _begin, _end) for (auto _i = _begin - (_begin > _end); _i != _end - (_begin > _end); _i += 1 - 2 * (_begin > _end))
#define FORE(_i, _c) for (auto _i : _c)
#define FORER(_i, _c) for (auto &_i : _c)
#else
#define FOR(_i, _begin, _end) for (__typeof(_end) _i = _begin - (_begin > _end); _i != _end - (_begin > _end); _i += 1 - 2 * (_begin > _end))
#define FORE(_i, _c)
#define FORER(_i, _c)
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
//====================END=====================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

// Constants here
const ll base = 1e9;

// Pre-Build Function
void build()
{
}

// Actual Solver
void solve()
{
    int n, m;
    readln(n, m);
    int amax = 0, bmax = 0;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        smax(amax, i);
    }
    vector<int> b(m);
    for (auto &i : b)
    {
        cin >> i;
        smax(bmax, i);
    }
    ll ans = 0;
    int af, al, bf;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == amax)
        {
            af = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == amax)
        {
            al = i;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] == bmax)
        {
            bf = i;
            break;
        }
    }
    debug(af, al, bf);
    for (int i = 0; i <= af; i++)
        ans += a[i] * base + b[0];
    for (int i = 1; i <= bf; i++)
        ans += a[af] * base + b[i];
    for (int i = af + 1; i <= al; i++)
        ans += a[i] * base + b[bf];
    for (int i = bf + 1; i < m; i++)
        ans += a[al] * base + b[i];
    for (int i = al + 1; i < n; i++)
        ans += a[i] * base + b[m - 1];
    cout << ans << endl;
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