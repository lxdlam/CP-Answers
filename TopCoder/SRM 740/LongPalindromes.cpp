#include <bits/stdc++.h>

using namespace std;

#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)

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

template <typename T>
T cd(T a, T b)
{
    return (a + b - 1) / b;
}

template <typename T>
bool se(T &a, T &b)
{
    if (a < b)
        return false;
    swap(a, b);
    return true;
}

const int INF = 0x3f3f3f3f;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;

class LongPalindromes
{
  private:
    // Constants
    const ll MOD = 1e9 + 7;

    // Useful Inner Method
    template <class T>
    struct Matrix
    {
        int row;
        int col;
        vector<vector<T>> data;

        Matrix(int _row = 0, int _col = 0)
        {
            resize(_row, _col);
            this->clear();
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

        void clear()
        {
            for (auto &i : data)
                for (auto &j : i)
                    j = 0;
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
                auto t = a[i][k] % mod;
                for (int j = 0; j < b.col; j++)
                    temp[i][j] = (temp[i][j] + t * b[k][j] % mod) % mod;
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

    template <class T>
    vector<T> mulVector(Matrix<T> mat, const vector<T> &vec, T mod = 1e9 + 7)
    {
        vector<T> ret;

        int n = mat.row, m = mat.col;

        if (n != vec.size())
            return ret;

        ret.resize(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ret[i] = (ret[i] + vec[j] * mat[i][j] % mod) % mod;

        return ret;
    }

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

    template <class T>
    void add(T &lhs, T rhs, T mod = 1e9 + 7)
    {
        lhs = (lhs + rhs) % mod;
    }

    template <class T>
    void sub(T &lhs, T rhs, T mod = 1e9 + 7)
    {
        lhs = (lhs - rhs + mod) % mod;
    }

    // Solver

  public:
    int count(int repeats, string pattern)
    {
        int len = pattern.size();
        if (len == 1)
            return static_cast<int>(fp(2, repeats));

        Matrix<ll> t(2 * len, 2 * len), m(2 * len, 2 * len);
        for (int i = 0; i < 2 * len; i++)
            t[i][i] = 1;

        for (int k = 0; k < len; k++)
        {
            m.clear();
            for (int i = 0; i < len; i++)
            {
                m[i][i] = 1;
                m[len + i][i] = 1; // dp^(len-1)[i]
                add(m[i][(i + 1) % len], 1LL); // dp^(len-1)[i+1]
                if (pattern[i] != pattern[(i + k) % len])
                    sub(m[i][(i + 1) % len + len], 1LL); // dp^(len-2)[i+1]
            }

            t = mul(m, t);
        }

        t = fp(t, 1LL * repeats);

        vll v(2 * len);
        for (int i = 0; i < len; i++)
            v[i] = 1;

        vll res = mulVector(t, v);

        return static_cast<int>(res[0]);
    }
};