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

class ResistorFactory
{
  private:
    // Constants

    // Useful Inner Method
    struct Node
    {
        double val;
        int pos;

        bool operator<(const Node &n) const
        {
            return val > n.val;
        }
    }

    public : ResistorFactory()
    {
    }

    vector<int> construct(long long nanoOhms)
    {
        // Solution here
        vector<int> ans;
        vector<Node> val;

        val.pb({1e9, 0});

        for (int i = 0; i < 30; i++)
        {
            ans.pb(i);
            ans.pb(i);
            ans.pb(0);
            val.pb({val.back().val * 2, (int)val.size()});
        }

        ans.pb(0);
        ans.pb(0);
        ans.pb(1);
        val.pb({val[0].val / 2, (int)val.size()});

        for (int i = 0; i < 30; i++)
        {
            ans.pb(i + 31);
            ans.pb(i + 31);
            ans.pb(1);
            val.pb({val.back().val / 2, (int)val.size()});
        }

        int sz = val.size();
        int cur = ans.size() / 3;

        double p = 1.0 * nanoOhms - 0.93;

        sort(val.begin(), val.end());

        for (int i = 0; i < sz && p >= 0; i++)
        {
            if (p > val[i].val)
            {
                ans.pb(cur);
                ans.pb(val[i].pos);
                ans.pb(0);
                cur = ans.size() / 3;
                p -= val[i].val;
            }
        }

        return ans;
    }
};