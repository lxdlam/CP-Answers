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

namespace FFT
{
typedef std::complex<double> Complex;
typedef std::vector<Complex> vc;

const double EPS = 0.5;

const int MaxL = 18, MaxN = 1 << MaxL;
vc eps(MaxN), inv_eps(MaxN);

void init_eps(int p)
{
    double pi = acos(-1);
    double angle = 2.0 * pi / p;
    for (int i = 0; i != p; i++)
    {
        eps[i] = Complex(cos(i * angle), sin(i * angle));
        inv_eps[i] = conj(eps[i]);
    }
}

void transform(int n, vc &x, const vc &w)
{
    for (int i = 0, j = 0; i != n; ++i)
    {
        if (i > j)
            swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1)
            ;
    }

    for (int i = 2; i <= n; i <<= 1)
    {
        int m = i >> 1;
        for (int j = 0; j < n; j += i)
        {
            for (int k = 0; k != m; ++k)
            {
                Complex z = x[j + m + k] * w[n / i * k];
                x[j + m + k] = x[j + k] - z;
                x[j + k] += z;
            }
        }
    }
}
} // namespace FFT

class SumOfArrays
{
  private:
    // Constants
    static const int K = 10;
    static const int Max = 2e5 + 10;
    int p = 1;
    vll A, B;

    // Useful Inner Method

    // Solver
    inline string solve()
    {
        vi a(p), b(p), c(p);

        vi ta, tb;

        for (auto i : A)
            a[i]++;
        for (auto i : B)
            b[i]++;

        FOR(i, 0, Max + 1)
        {
            if (a[i] >= K)
                ta.pb(i);
            if (b[i] >= K)
                tb.pb(i);
        }

        for (auto i : ta)
            for (auto j : tb)
                c[i + j] += min(a[i], b[j]) - K + 1; // Avoid extra addition

        FOR(i, 1, K)
        {
            FFT::vc x(p), y(p);
            FOR(j, 0, Max + 1)
            {
                x[j] += a[j] >= i;
                y[j] += b[j] >= i;
            }

            FFT::transform(p, x, FFT::eps);
            FFT::transform(p, y, FFT::eps);

            FOR(j, 0, p)
            x[j] *= y[j];

            FFT::transform(p, x, FFT::inv_eps);

            FOR(j, 0, Max + 1)
            c[j] += (int)(x[j].real() / p + FFT::EPS);
        }

        int X = -1, Y = 0;

        FOR(i, 0, Max + 1)
        if (X <= c[i])
        {
            X = c[i];
            Y = i;
        }

        stringstream ss;
        ss << X << ' ' << Y;
        return ss.str();
    }

  public:
    string findbestpair(int n, vector<int> Aseed, vector<int> Bseed)
    {
        // Build
        A.resize(n);
        B.resize(n);

        A[0] = Aseed[0];
        A[1] = Aseed[1];
        B[0] = Bseed[0];
        B[1] = Bseed[1];

        FOR(i, 2, n)
        {
            A[i] = (A[i - 1] * Aseed[2] % Aseed[5] + A[i - 2] * Aseed[3] % Aseed[5] + Aseed[4]) % Aseed[5];
            B[i] = (B[i - 1] * Bseed[2] % Bseed[5] + B[i - 2] * Bseed[3] % Bseed[5] + Bseed[4]) % Bseed[5];
        }

        while (p < Max)
            p <<= 1;

        FFT::init_eps(p);

        return solve();
    }
};