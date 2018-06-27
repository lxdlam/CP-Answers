#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>
#include <iterator>
#include <sstream>

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
ll v[SIZE];
bool cur[SIZE];
int din[SIZE], dout[SIZE];
vector<vi> G(SIZE);

int cnt = 1;

int lowbit(int x)
{
    return x & (-x);
}

void update(int idx, int n, ll val)
{
    while (idx <= n)
    {
        v[idx] += val;
        idx += lowbit(idx);
    }
}

ll query(int idx, int n)
{
    ll ans = 0;
    while (idx)
    {
        ans += v[idx];
        idx -= lowbit(idx);
    }
    return ans;
}

void dfs(int idx)
{
    din[idx] = cnt;
    FOR(i, 0, G[idx].size())
    {
        cnt++;
        dfs(G[idx][i]);
    }
    dout[idx] = cnt;
}

// Pre-Build Function
inline void build()
{
    memset(v, 0, sizeof(v));
    memset(din, 0, sizeof(din));
    memset(dout, 0, sizeof(dout));
    memset(cur, false, sizeof(cur));
    FOR(i, 0, SIZE)
    G[i].clear();
}

// Actual Solver
inline void solve()
{
    int n, m;
    int x, y;
    scanf("%d\n", &n);
    FOR(i, 0, n - 1)
    {
        scanf("%d%d\n", &x, &y);
        G[x].pb(y);
    }

    dfs(1);

    FOR(i, 1, n + 1)
    cur[i] = true, update(din[i], n, 1);

    scanf("%d\n", &m);
    char op;
    while (m--)
    {
        scanf("%c %d\n", &op, &x);
        if (op == 'Q')
            printf("%lld\n", query(dout[x], n) - query(din[x] - 1, n));
        else
        {
            update(din[x], n, cur[x] ? -1 : 1);
            cur[x] = !cur[x];
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

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

// Alternative solution
// Using Linked Forward Star 
// const int SIZE = 1e5 + 10;

// struct Edge
// {
//     int next, to, w;

//     Edge() : next(0), to(0), w(0) {}
// };

// Edge E[SIZE];
// int head[SIZE];
// int cnt = 0;
// int Dcnt = 1;
// int n;

// void add_edge(int u, int v, int w)
// {
//     E[++cnt].next = head[u];
//     E[cnt].to = v;
//     E[cnt].w = w;
//     head[u] = cnt;
// }

// void dfs(int idx)
// {
//     din[idx] = Dcnt;
//     int p = head[idx];
//     while (p)
//     {
//         Dcnt++;
//         dfs(E[p].to);
//         p = E[p].next;
//     }
//     dout[idx] = Dcnt;
// }

// inline void solve()
// {
//     int m;
//     int x, y;
//     cin >> n;
//     FOR(i, 0, n - 1)
//     {
//         cin >> x >> y;
//         add_edge(x, y, 1);
//     }

//     dfs(1);

//     FOR(i, 1, n + 1)
//     cur[i] = true, update(din[i], 1);

//     cin >> m;
//     char op;
//     while (m--)
//     {
//         cin >> op >> x;
//         if (op == 'Q')
//             cout << query(dout[x]) - query(din[x] - 1) << endl;
//         else
//         {
//             update(din[x], cur[x] ? -1 : 1);
//             cur[x] = !cur[x];
//         }
//     }
// }