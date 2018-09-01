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
const int CHAR_SIZE = 26;
const char CHAR_START = 'a';
const int SIZE = 1e6 + 10; // String size
const ll MOD = 19930726;

typedef map<ll, ll, greater<ll>> mpll;

mpll m;

ll fp(ll base, ll expr, ll mod = 1e9 + 7)
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

struct PAM
{
    int node[SIZE][CHAR_SIZE];
    int fail[SIZE];
    int cnt[SIZE]; // distinct palindromes in position at node i
    int num[SIZE]; // the number of palindroms which end with the end of longest palindrome at node i
    int len[SIZE]; // length of the palindrome at node i
    int s[SIZE];

    int last; // the longest palindrome's node
    int n;    // count of character
    int p;    // count of nodes

    int new_node(int le)
    {
        for (int i = 0; i < CHAR_SIZE; i++)
            node[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = le;
        return p++;
    }

    void init()
    {
        p = 0;
        new_node(0);
        new_node(-1);

        last = n = 0;
        s[0] = -1;
        fail[0] = 1;
    }

    int get_fail(int x)
    {
        while (s[n - len[x] - 1] != s[n])
            x = fail[x];
        return x;
    }

    void add(char ch)
    {
        int c = ch - CHAR_START;
        s[++n] = c;
        int cur = get_fail(last);
        if (!node[cur][c])
        {
            int now = new_node(len[cur] + 2);
            fail[now] = node[get_fail(fail[cur])][c];
            node[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = node[cur][c];
        cnt[last]++;
    }

    void get_cnt()
    {
        for (int i = p - 1; i >= 0; i--)
        {
            cnt[fail[i]] += cnt[i];
            if (len[i] & 1)
                m[len[i]] += cnt[i];
        }
    }

    int get_num() { return num[n]; }
} pam;

// Pre-Build Function
inline void build()
{
    pam.init();
}

// Actual Solver
inline void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 1;
    FOR(i, 0, n)
    pam.add(s[i]);

    pam.get_cnt();

    for (mpll::iterator it = m.begin(); it != m.end(); it++)
    {
        ans = (ans * fp(it->first, min(it->second, k), MOD)) % MOD;
        k -= it->second;
        if (k <= 0)
            break;
    }

    if (k > 0)
        cout << "-1\n";
    else
        cout << ans << '\n';
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