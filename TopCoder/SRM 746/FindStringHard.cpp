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

class FindStringHard
{
  private:
    // Constants

  public:
    FindStringHard()
    {
    }

#define GET(f) (f ? 'a' : 'b')

    inline bool check(int c1, int n1, int c2, int n2)
    {
        return c1 * n1 + c2 * n2 <= 50;
    }

    inline string cal(int c, int n, bool rev)
    {
        stringstream ss;
        string t;

        for (int j = 0; j < c; j++)
            ss << GET(rev);
        for (int j = 0; j < c; j++)
            ss << GET(!rev);

        t = ss.str();

        for (int i = 1; i < n; i++)
            ss << t;

        return ss.str();
    }

    string withAntipalindromicSubstrings(int n)
    {
        stringstream ss;

        for (int i = 32; i >= 1; i--)
        {
            while (i * (i + 1) <= n)
            {
                n -= i * (i + 1);
                for (int j = 0; j < i; j++)
                    ss << "ab";
                ss << "a";
            }
        }

        if (n & 1)
            ss << "ab";

        return ss.str();
    }
};