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
#if __cplusplus >= 201402L
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
//====================END=====================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

// Constants here
vector<string> v;
vi can;

void row(vector<int> &vis, int r)
{
    FOR(i, 0, 9)
    if (v[r][i] != '?')
        vis[v[r][i] - '0'] = 0;
}

void col(vector<int> &vis, int c)
{
    FOR(i, 0, 9)
    if (v[i][c] != '?')
        vis[v[i][c] - '0'] = 0;
}

void sec(vector<int> &vis, int r, int c)
{
    r = r / 3 * 3;
    c = c / 3 * 3;
    FOR(i, r, r + 3)
    FOR(j, c, c + 3)
    if (v[i][j] != '?')
        vis[v[i][j] - '0'] = 0;
}

int dfs(int i, int j)
{
    int res = 0;
    if (v[i][j] != '?')
    {
        if (i == 8 && j == 8)
            return 1;
        else if (i == 8)
            return dfs(0, j + 1);
        return dfs(i + 1, j);
    }
    vi vis = can;

    row(vis, i);
    col(vis, j);
    sec(vis, i, j);

    FOR(k, 1, 10)
    {
        if (vis[k])
        {
            v[i][j] = vis[k] + '0';

            if (i == 8 && j == 8)
                res = 1;
            else if (i == 8)
                res = dfs(0, j + 1);
            else
                res = dfs(i + 1, j);

            if (res)
                break;
        }

        v[i][j] = '?';
    }

    return res;
}

// Pre-Build Function
void build()
{
    v.resize(9);
    FOR(i, 0, 10)
    can.push_back(i);
}

// Actual Solver
void solve()
{
    int T;
    cin >> T;
    string s;
    FOR(i, 0, T)
    {
        if (i)
            cin >> s;
        FOR(i, 0, 9)
        cin >> v[i];

        if (dfs(0, 0))
        {
            FOR(i, 0, 9)
            cout << v[i] << endl;
        }
        else
            cout << "impossible" << endl;

        if (i != T - 1)
            cout << "---" << endl;
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