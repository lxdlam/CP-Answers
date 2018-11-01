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
int n, m;
int sx, sy;
int tx, ty;

int diro[][2] = {{0, -1}, {0, 1}};
int dirz[][2] = {{-1, 0}, {1, 0}};
vector<deque<bool>> board;
vector<vector<bitset<2>>> vis;

struct Node
{
    int x, y;
    int cur;
    int step;

    Node() : x(0), y(0), cur(0), step(0) {}
};

inline bool check(Node &s)
{
    if (s.x < 0 || s.x >= n || s.y < 0 || s.y >= m)
        return false;
    return !vis[s.x][s.y][s.cur];
}

inline int bfs()
{
    queue<Node> q;
    Node s, n, t;
    s.x = sx, s.y = sy;
    s.cur = 0;
    vis[sx][sy][0] = 1;

    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();

        if (t.x == tx && t.y == ty)
            return t.step;

        if (board[t.x][t.y] != t.cur)
        {
            for (int i = 0; i < 2; i++)
            {
                n = t;
                n.cur = !n.cur;
                n.step++;
                n.x += diro[i][0];
                n.y += diro[i][1];
                if (check(n))
                {
                    vis[n.x][n.y][n.cur] = true;
                    q.push(n);
                }
            }
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                n = t;
                n.cur = !n.cur;
                n.step++;
                n.x += dirz[i][0];
                n.y += dirz[i][1];
                if (check(n))
                {
                    vis[n.x][n.y][n.cur] = true;
                    q.push(n);
                }
            }
        }
    }

    return -1;
}

void init()
{
    board.clear();
    board.resize(n);
    vis.clear();
    vis.resize(n);
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    tcase()
    {
        int t;
        cin >> n >> m;
        init();
        for (int i = 0; i < n; i++)
        {
            vis[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> t;
                if (t)
                    board[i].pb(true);
                else
                    board[i].pb(false);
            }
        }
        cin >> sx >> sy >> tx >> ty;
        sx--;
        sy--;
        tx--;
        ty--;
        cout << bfs() << '\n';
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