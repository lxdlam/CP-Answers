#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

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
namespace io
{
const int MAXSIZE = 1 << 22;
inline char gc()
{
    static char In[MAXSIZE], *at = In, *en = In;
    if (at == en)
        en = (at = In) + fread(In, 1, MAXSIZE, stdin);
    return at == en ? EOF : *at++;
}
template <class T>
inline void read(T &x)
{
    char c;
    while (c = gc(), !isdigit(c) && c != '-')
        ;
    bool f = c == '-';
    x = f ? 0 : c - '0';
    for (c = gc(); isdigit(c); c = gc())
        x = x * 10 + c - '0';
    if (f)
        x = -x;
}
char Out[MAXSIZE], *cur = Out, *end = Out + MAXSIZE - 100;
void flush()
{
    fwrite(Out, 1, cur - Out, stdout);
    cur = Out;
}
template <typename T>
inline void write(T x, char c = '\n')
{
    static int S[20], *top;
    top = S;
    if (x < 0)
        *cur++ = '-', x = -x;
    do
    {
        *++top = x % 10, x /= 10;
    } while (x);
    while (top != S)
        *cur++ = *top-- + '0';
    *cur++ = c;
    if (cur >= end)
        flush();
}
} // namespace io

const int SIZE = 2e5 + 10; // Number of edges

struct Edge
{
    ll next, to, w;

    Edge() : next(0), to(0), w(0) {}
};

Edge E[SIZE];
int last[SIZE];
int cnt = 0;

ll dis[SIZE][20];

void add_edge(int u, int v, int w = 1)
{
    E[++cnt].next = last[u];
    E[cnt].to = v;
    E[cnt].w = w;
    last[u] = cnt;
}

struct atom
{
    ll x, y, k;
};

struct cmp
{
    bool operator()(const atom &a, const atom &b)
    {
        return a.x == b.x ? (a.y > b.y) : (a.x > b.x);
    }
};

using pqat = __gnu_pbds::priority_queue<atom, cmp, __gnu_pbds::pairing_heap_tag>;

void init()
{
    memset(E, 0, sizeof E);
    memset(last, 0, sizeof last);
    memset(dis, 0x3f, sizeof dis);
    cnt = 0;
}

void dijkstra(int n, int k)
{
    pqat pq;

    dis[1][0] = 0;
    pq.push({0, 1, 0});

    while (pq.size())
    {
        auto a = pq.top();
        pq.pop();
        int x = a.y;
        int c = a.k;
        if (dis[x][c] < a.x)
            continue;
        for (int i = last[x]; i; i = E[i].next)
        {
            int t = E[i].to;
            if (dis[t][c] > dis[x][c] + E[i].w)
            {
                dis[t][c] = dis[x][c] + E[i].w;
                pq.push({dis[t][c], t, c});
            }
            if (c + 1 <= k)
            {
                // Set distance to 0
                // The next layer of the graph
                if (dis[t][c + 1] > dis[x][c])
                {
                    dis[t][c + 1] = dis[x][c];
                    pq.push({dis[t][c + 1], t, c + 1});
                }
            }
        }
    }
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    using namespace io;
    int T;
    read(T);
    while (T--)
    {
        init();
        int n, m, k;
        read(n);
        read(m);
        read(k);
        int u, v, p;
        while (m--)
        {
            read(u);
            read(v);
            read(p);
            add_edge(u, v, p);
        }
        dijkstra(n, k);
        write(dis[n][k]);
    }
    flush();
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