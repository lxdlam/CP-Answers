#include <bits/stdc++.h>

using namespace std;

#define TemplateVersion "3.1.1"
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;
//====================END=====================

// Constants here
const int SIZE = 1e6 + 10;
vi front[SIZE], tail[SIZE];
bool fc[SIZE] = {false}, ec[SIZE] = {false};
vector<string> v(1), vt(1);
unordered_map<string, int> h;

// Pre-Build Function
void fdfs(int pos);

void edfs(int pos)
{
    if (ec[pos])
        return;
    ec[pos] = true;
    for (auto i : tail[pos])
        fdfs(i);
}

void fdfs(int pos)
{
    if (fc[pos])
        return;
    fc[pos] = true;
    for (auto i : front[pos])
        edfs(i);
}

inline void build()
{
}

// Actual Solver
inline void solve()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    string t, s;
    int cnt = 1;
    while (ss >> t)
    {
        v.pb(t);
        if (t.back() == '.' || t.back() == ',')
            t.pop_back();
        if (!h[t])
            h[t] = cnt++;
        vt.pb(t);
    }
    FOR(i, 1, vt.size() - 1)
    {
        t = vt[i];
        s = vt[i + 1];
        if (v[i].back() != '.')
        {
            tail[h[t]].pb(h[s]);
            front[h[s]].pb(h[t]);
        }
    }
    FOR(i, 1, vt.size() - 1)
    {
        t = vt[i];
        s = vt[i + 1];
        if (v[i].back() == ',' || (v[i].back() != '.' && ec[h[t]]) || (v[i].back() != '.' && fc[h[s]]))
        {
            edfs(h[t]);
            fdfs(h[s]);
        }
    }
    FOR(i, 1, v.size())
    {
        if (v[i].back() == ',' || v[i].back() == '.')
            cout << v[i] << " ";
        else if (ec[h[vt[i]]])
            cout << v[i] << ", ";
        else
            cout << v[i] << " ";
    }
    cout << endl;
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