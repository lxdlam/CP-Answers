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
ll Mod(ll n, ll m)
{
    return n < m ? n : (n % m + m);
}

template <class T>
struct Matrix
{
    int row;
    int col;
    vector<vector<T>> data;

    Matrix(int _row = 0, int _col = 0)
    {
        resize(_row, _col);
    }

    Matrix(vector<vector<T>> d)
    {
        row = d.size();
        col = d[0].size();
        data.resize(row);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i].push_back(d[i][j]);
    }

    void resize(int _row, int _col)
    {
        row = _row;
        col = _col;
        data.resize(row);
        for (auto &i : data)
            i.resize(col);
    }

    T trace()
    {
        if (col != row)
            return -1;
        T ans = 0;
        for (int i = 0; i < row; i++)
            ans += data[i][i];
        return ans;
    }

    vector<T> &operator[](int pos)
    {
        return ref(data[pos]);
    }

    Matrix<T> operator-()
    {
        Matrix t(this->data);
        for (auto &i : t.data)
        {
            for (auto &j : i)
            {
                j = -j;
            }
        }
        return t;
    }

    bool empty()
    {
        return row == 0 || col == 0;
    }
};

template <class T>
Matrix<T> add(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    Matrix<T> temp;

    if (a.row != b.row || a.col != b.col)
        return temp;

    temp.resize(a.row, a.col);

    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
            temp[i][j] = (a[i][j] + b[i][j]) % mod;
    }
}

template <class T>
Matrix<T> minus(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    return add(a, -b);
}

template <class T>
Matrix<T> mul(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7)
{
    Matrix<T> temp;

    if (a.col != b.row)
        return temp;

    temp.resize(a.row, b.col);

    for (int i = 0; i < a.row; i++)
    {
        for (int k = 0; k < a.col; k++)
        {
            auto t = Mod(a[i][k], mod);
            for (int j = 0; j < b.col; j++)
                temp[i][j] = Mod(temp[i][j] + Mod(t * b[k][j], mod), mod);
        }
    }

    return temp;
}

template <class T>
Matrix<T> fp(Matrix<T> base, T expr, T mod = 1e9 + 7)
{
    Matrix<T> ans(base.data), t(base.data);
    expr--;
    while (expr)
    {
        if (expr & 1)
            ans = mul(ans, t, mod);
        t = mul(t, t, mod);
        expr >>= 1;
    }
    return ans;
}

ll fp(ll base, ll expr, ll mod = 1e9 + 7)
{
    ll ans = 1;
    //base %= mod;
    while (expr)
    {
        if (expr & 1LL)
            ans = Mod(ans * base, mod);
        base = Mod(base * base, mod);
        expr >>= 1LL;
    }
    return Mod(ans, mod);
}

ll getFib(ll n, ll mod)
{
    Matrix<ll> mat({{1, 1}, {1, 0}});
    return fp(mat, n, mod).data[0][1];
}

ll Phi(ll n)
{
    ll phi = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            phi /= i;
            phi *= i - 1;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
    {
        phi /= n;
        phi *= n - 1;
    }
    return phi;
}

// Pre-Build Function
inline void build()
{
}

// Actual Solver
inline void solve()
{
    ll a, b, p, n;
    int T;
    cin >> T;
    FOR(i, 1, T + 1)
    {
        cout << "Case #" << i << ": ";
        readln(a, b, p, n);
        if (n == 1)
            cout << a % p << '\n';
        else if (n == 2)
            cout << b % p << '\n';
        else
        {
            auto phi = Phi(p);
            cout << fp(a, getFib(n - 2, phi), p) * fp(b, getFib(n - 1, phi), p) % p << '\n';
        }
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