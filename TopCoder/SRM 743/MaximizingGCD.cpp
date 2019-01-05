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

class MaximizingGCD
{
  private:
    // Constants

    // Useful Inner Method

  public:
    MaximizingGCD()
    {
    }

    int maximumGCDPairing(vector<int> A)
    {
        // Solution here
        set<int> choice;
        int len = A.size();
        int ans = 1;

        auto count_divisors = [&](int num) {
            for (int i = 1; i * i < num; i++)
                if (num % i == 0)
                    choice.insert(i), choice.insert(num / i);
        };

        for (int i = 1; i < len; i++)
            count_divisors(A[0] + A[i]);

        for (auto di : choice)
        {
            bool flag = true;
            map<int, int> re;
            for (auto num : A)
                re[num % di]++;
            for (auto it : re)
            {
                if (it.first == 0 || 2 * it.first == di)
                {
                    if (it.second & 1)
                        flag = false;
                }
                else if (!re.count(di - it.first) || it.second != re[di - it.first])
                    flag = false;
            }

            smax(ans, flag ? di : 1);
        }

        return ans;
    }
};