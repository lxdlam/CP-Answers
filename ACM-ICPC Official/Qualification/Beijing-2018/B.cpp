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
int n;
vector<string> v;

bool dfs(int i, int j, string s, string t)
{
    if (i >= s.size())
        return true;
    if (j >= t.size())
        return false;
    bool ret = false;

    for (int p = j; p < t.size(); p++)
        if (s[i] == t[p])
            ret = ret || dfs(i + 1, p + 1, s, t);

    return ret;
}

bool check(string s)
{
    if (!s.size())
        return false;
    bool ret = true;
    for (int i = 1; i < n && ret; i++)
    {
        bool sub = false;
        int lent = v[i].size() / 2;
        for (int c = 0; c < lent && !sub; c++)
            sub = sub || dfs(0, 0, s, v[i].substr(c, lent));
        ret = ret && sub;
    }

    return ret;
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    stringstream ss;
    while (cin >> n)
    {
        v.resize(n);
        for (auto &i : v)
        {
            cin >> i;
            i += i;
        }

        string ans = "";

        sort(all(v), [](const string &a, const string &b) { return a.size() < b.size(); });

        int MAXN = v[0].size() / 2;

        for (int st = 0; st < MAXN; st++)
        {
            for (int i = 0; i < (1 << MAXN); i++)
            {
                ss.str("");
                for (int c = 0; c < MAXN; c++)
                    if (i & (1 << c))
                        ss << v[0][st + c];
                string t = ss.str();
                if (check(t))
                {
                    if (ans.size() < t.size())
                        ans = t;
                    if (ans.size() == t.size() && ans > t)
                        ans = t;
                }
            }
        }
        if (ans.size())
            cout << ans << '\n';
        else
            cout << "0\n";
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