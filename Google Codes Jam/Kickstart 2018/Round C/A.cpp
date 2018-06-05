// NOT SOLVED
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
#define CLEAR(n) memset((n), 0, sizeof(n))
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
const int SIZE = 1010;
int g[SIZE][SIZE];
int ag[SIZE][SIZE];
int sp[SIZE];
bool v[SIZE];
si cycle;

bool dfs(int cur, int from, int n)
{
    if (v[cur])
        return true;
    v[cur] = true;

    FOR(i, 1, n + 1)
    {
        if (i == cur || i == from)
            continue;
        if (g[cur][i] && dfs(i, cur, n))
        {
            if (cycle.count(i))
                return false;
            cycle.insert(i);
            return true;
        }
    }
    return false;
}

void dijkstra(int n)
{
    bool vis[SIZE] = {false};
    FOR(i, 1, n + 1)
    {
        if (cycle.count(i))
            vis[i] = true;
        sp[i] = INF;
    }
    sp[0] = 0;
    FOR(i, 0, n + 1)
    {
        int x, m = INF;
        FOR(y, 0, n + 1)
        {
            if (!vis[y] && sp[y] <= m)
            {
                m = sp[y];
                x = y;
            }
        }
        vis[x] = true;
        FOR(y, 0, n + 1)
        smin(sp[y], sp[x] + ag[x][y]);
    }
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int T;
    cin >> T;
    FOR(kase, 1, T + 1)
    {
        cout << "Case #" << kase << ": ";
        int n;
        cin >> n;
        vector<pii> tg;

        CLEAR(g);
        CLEAR(sp);
        memset(ag, 0x3f, sizeof(ag));
        CLEAR(v);
        cycle.clear();

        int x, y;

        FOR(i, 0, n)
        {
            cin >> x >> y;
            g[x][y] = g[y][x] = 1;
            tg.push_back(mp(x, y));
        }

        // Find the cycle
        dfs(1, 1, n);

        // Build the adjusted graph
        // Use the Special 0 to represent the cycle.
        for (auto [x, y] : tg)
        {
            if (cycle.count(x) && cycle.count(y))
                continue;
            else if (cycle.count(x))
                ag[0][y] = ag[y][0] = 1;
            else if (cycle.count(y))
                ag[x][0] = ag[0][x] = 1;
            else
                ag[x][y] = ag[y][x] = 1;
        }

        // Run the dijkstra
        dijkstra(n);

        FOR(i, 1, n + 1)
        {
            if (i != 1)
                cout << ' ';
            if (cycle.count(i))
                cout << "0";
            else
                cout << sp[i];
        }
        cout << endl;
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