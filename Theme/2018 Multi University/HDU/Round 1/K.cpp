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

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int hh, mm;
        int h, m;
        char offset[20];
        memset(offset, 0, sizeof(offset));
        scanf("%d%d", &hh, &mm);
        scanf("%s", offset);
        bool p = offset[strlen(offset) - 2] == '.';
        if (offset[3] == '+')
        {
            if (p)
                sscanf(offset, "UTC+%d.%d", &h, &m);
            else
                sscanf(offset, "UTC+%d", &h);
        }
        else
        {
            if (p)
                sscanf(offset, "UTC-%d.%d", &h, &m);
            else
                sscanf(offset, "UTC-%d", &h);
        }
        bool flag;
        if (p)
            flag = h + m * 0.1 < 8 || offset[3] == '-';
        else
            flag = h < 8 || offset[3] == '-';
        if (!flag)
            h -= 8;
        else
        {
            if (offset[3] == '-')
                h += 8;
            else if (!p)
                h = 8 - h;
            else
            {
                int t = 80 - 10 * h - m;
                h = t / 10;
                m = t % 10;
            }
        }
        if (!flag)
        {
            if (p)
            {
                mm += 60 * m * 0.1;
                if (mm >= 60)
                {
                    mm -= 60;
                    hh += 1;
                }
            }
            hh = (hh + h) % 24;
        }
        else
        {
            if (p)
            {
                mm -= 60 * m * 0.1;
                if (mm < 0)
                {
                    mm += 60;
                    hh -= 1;
                }
            }
            hh = hh - h;
            while (hh < 0)
                hh += 24;
        }
        printf("%02d:%02d\n", hh, mm);
    }
}

int main()
{
    //    ios::sync_with_stdio(false);
    //    cin.tie(nullptr);
    //    cout.tie(nullptr);

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