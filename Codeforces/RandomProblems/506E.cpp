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
const int MOD = 10007;
const int SIZE = 210;
const int MSIZE = 2 * SIZE;

int dp[SIZE][SIZE][SIZE];
string s;
int n;

int MT[MSIZE][MSIZE];
ll tmp[MSIZE][MSIZE];

void mul(int a[][MSIZE], int b[][MSIZE])
{
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < MSIZE; i++)
    {
        for (int j = 0; j < MSIZE; j++)
        {
            ll s = 0;
            for (int k = i; k < j + 1; k++)
                s += a[i][k] * b[k][j];
            tmp[i][j] = s % MOD;
        }
    }

    FOR(i, 0, MSIZE)
    FOR(j, 0, MSIZE)
    a[i][j] = tmp[i][j];
}

void fp(int a[][MSIZE], int expr)
{
    memset(MT, 0, sizeof MT);
    for (int i = 0; i < MSIZE; i++)
        MT[i][i] = 1;

    while (expr)
    {
        if (expr & 1)
            mul(MT, a);
        mul(a, a);
        expr >>= 1;
    }

    FOR(i, 0, MSIZE)
    FOR(j, 0, MSIZE)
    a[i][j] = MT[i][j];
}

int get(int l, int r, int i)
{
    int &ret = dp[l][r][i];
    if (ret != -1)
        return ret;
    ret = 0;

    if (l == r)
    {
        if (i == 0)
            ret = 1;
    }
    else
    {
        if (s[l] == s[r])
        {
            if (l + 1 == r)
            {
                if (i == 0)
                    ret = 1;
            }
            else
                ret = get(l + 1, r - 1, i);
        }
        else if (i > 0)
            ret = get(l + 1, r, i - 1) + get(l, r - 1, i - 1);
    }

    ret %= MOD;
    return ret;
}

// Pre-Build Function
inline void build()
{
    memset(dp, -1, sizeof dp);
}

// Actual Solver
inline void solve()
{
    cin >> s >> n;
    int len = s.size();
    n += len;
    int m = (n + 1) / 2;

    int N24 = len - 1;
    int N25 = (len + 1) / 2;
    int N26 = N25;
    int S = N24 + N25 + N26;

    // Matrix<int> A(MSIZE, MSIZE);
    int A[MSIZE][MSIZE];
    int t[MSIZE][MSIZE];
    int C[MSIZE][MSIZE];

    for (int i = 0; i < S; i++)
    {
        if (i < N24)
        {
            t[i][i] = A[i][i] = 24; // Self transition
            t[i][i + 1] = A[i][i + 1] = 1;
        }
        else if (i < N24 + N25)
        {
            t[i][i] = A[i][i] = 25;
            if (i < N24 + N25 - 1)
                t[i][i + 1] = A[i][i + 1] = 1; // To the next
            t[i][i + N25] = A[i][i + N25] = 1; // To the GOAL
        }
        else
            t[i][i] = A[i][i] = 26;
    }

    fp(A, m - 1);

    FOR(i, 0, S)
    FOR(j, 0, S)
    C[i][j] = A[i][j];

    mul(A, t); // m

    // count the answer
    ll ans = 0;
    for (int i = 0; i < len; i++)
    {
        int n25 = (len - i + 1) / 2;
        bool flag = (len - i) % 2 == 0;

        if (m < i + n25)
            continue; // There is no such a string

        int w = get(0, len - 1, i);
        ans = (ans + w * A[N24 - i][N24 + N25 + n25 - 1]) % MOD;

        if (n % 2 && flag)
            ans = (ans + MOD * MOD - w * C[N24 - i][N24 + n25 - 1]) % MOD;
    }

    cout << ans % MOD << '\n';
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
