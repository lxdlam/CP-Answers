#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.7.0"
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
#define clr(x) memset((x), 0, sizeof(x))
#define infty(x) memset((x), 0x3f, sizeof(x))
#define tcase()         \
    int T;              \
    cin >> T;           \
    FOR(kase, 1, T + 1) \
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
const int SIZE = 1e5 + 10;

int dp[SIZE];
int ans[SIZE];
int upd[SIZE];
vector<int> G[SIZE], pref[SIZE], suf[SIZE];

function<int(int, int)> Mul;

void dfs(int cur, int fa)
{
    dp[cur] = 1;
    int len = G[cur].size();
    vector<int> fac;

    for (int i = 0; i < len; i++)
    {
        int v = G[cur][i];
        if (v == fa)
        {
            fac.pb(1);
            continue;
        }

        dfs(v, cur);
        fac.pb(dp[v] + 1);
        dp[cur] = Mul(dp[cur], dp[v] + 1);
    }

    int p = 1, q = 1;
    pref[cur].pb(1);
    suf[cur].pb(1);
    for (int i = 0; i < len; i++)
    {
        p = Mul(fac[i], p);
        q = Mul(fac[len - i - 1], q);
        pref[cur].pb(p);
        suf[cur].pb(q);
    }
}

void update(int cur, int fa)
{
    int len = G[cur].size();

    for (int i = 0; i < len; i++)
    {
        int v = G[cur][i];
        if (v == fa)
            continue;

        upd[v] = Mul(Mul(pref[cur][i], suf[cur][len - i - 1]), upd[cur]) + 1;
        ans[v] = Mul(dp[v], upd[v]);
        update(v, cur);
    }
}

// Pre-Build Function
inline void build()
{
    clr(dp);
    clr(ans);
}

// Actual Solver
inline void solve()
{
    int N, M;
    cin >> N >> M;

    Mul = [&M](int a, int b) {
        ll ans = 1LL * a % M;
        ans = (ans * b % M) % M;
        return static_cast<int>(ans % M);
    };

    for (int i = 1; i < N; i++)
    {
        int x, y;
        readln(x, y);
        G[x].pb(y);
        G[y].pb(x);
    }

    dfs(1, -1);
    ans[1] = dp[1];
    upd[1] = 1;
    update(1, -1);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
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