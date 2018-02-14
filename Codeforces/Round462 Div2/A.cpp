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
#else
#define debug(args...)
#endif
#if __cplusplus >= 201703L
template <typename... Args>
void readln(istream &in, Args &... args)
{
    ((in >> args), ...);
}
template <typename... Args>
void writeln(ostream &out, Args... args)
{
    ((out << args << " "), ...);
    out << endl;
}
#elif __cplusplus >= 201103L
void readln(istream &in)
{
}
template <typename T, typename... Args>
void readln(istream &in, T &a, Args &... args)
{
    in >> a;
    readln(in, args...);
}
void writeln(ostream &out)
{
    out << endl;
}
template <typename T, typename... Args>
void writeln(ostream &out, T a, Args... args)
{
    out << a << " ";
    writeln(out, args...);
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
#if __cplusplus >= 201402L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : _name)        \
        cin >> i;
#elif __cpluscplus >= 201103L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name;         \
    _name.resize(_size);         \
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
//====================END=====================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

// Constants here

// Pre-Build Function
void build()
{
}

// Actual Solver
void solve()
{
    int n, m;
    readln(cin, n, m);
    VIS(int, v1, n);
    VIS(int, v2, m);
    int pos = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    auto _begin = chrono::steady_clock::now();
#endif

    build();
    solve();

#ifdef LOCAL
    chrono::duration<double, milli> _duration = chrono::steady_clock::now() - _begin;
    cerr << "Elapsed Time: " << _duration.count() << "ms." << endl;
#endif

    return 0;
}