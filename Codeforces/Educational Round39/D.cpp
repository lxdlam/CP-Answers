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
int len(int start, int end)
{
    return end - start + 1;
}

// Pre-Build Function
void build()
{
}

// Actual Solver
void solve()
{
    int n, m, k;
    readln(n, m, k);
    vector<deque<int>> v(n);
    string s;
    int total = 0, cls = 0;
    FOR(i, 0, n)
    {
        cin >> s;
        FOR(j, 0, m)
        if (s[j] == '1')
            v[i].push_back(j), cls++;
        if (v[i].size() == 1)
            total++;
        else if (v[i].size() > 1)
            total += len(v[i].front(), v[i].back());
    }
    debug(total, cls);
    int side;
    int length;
    int pos;
    int tmp, tlen;
    while (k && cls)
    {
        pos = length = side = 0;
        FOR(i, 0, n)
        {
            if (v[i].size() != 0)
            {
                if (v[i].size() == 1)
                {
                    if (length < 1)
                    {
                        length = 1;
                        side = 0;
                        pos = i;
                    }
                }
                else if (v[i].size() == 2)
                {
                    if (length < len(v[i].front(), v[i].back()) - 1)
                    {
                        length = len(v[i].front(), v[i].back()) - 1;
                        side = 0;
                        pos = i;
                    }
                }
                else
                {
                    tmp = v[i].back();
                    tlen = len(v[i].front(), v[i].back());
                    v[i].pop_back();
                    if (length < tlen - len(v[i].front(), v[i].back()))
                    {
                        length = tlen - len(v[i].front(), v[i].back());
                        pos = i;
                        side = 1;
                    }
                    v[i].push_back(tmp);

                    tmp = v[i].front();
                    tlen = len(v[i].front(), v[i].back());
                    v[i].pop_front();
                    if (length < tlen - len(v[i].front(), v[i].back()))
                    {
                        length = tlen - len(v[i].front(), v[i].back());
                        pos = i;
                        side = 0;
                    }
                    v[i].push_front(tmp);
                }
            }
        }
        if (side == 0)
            v[pos].pop_front();
        else
            v[pos].pop_back();
        total -= length;
        k--, cls--;
    }
    cout << total << endl;
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