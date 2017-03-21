#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int k, t = 0;
    scanf("%d", &k);
    while (k--)
    {
        long long n, s1, s2, v1, v2, x, best = 0;
        scanf("%lld%lld%lld%lld%lld", &n, &s1, &v1, &s2, &v2);
        long long s = s1 * s2, v = max(s2 * v1, s1 * v2); //求s=s1*s2时的最大价值v。
        x = n / s * v;                                    //预处理获得的价值。
        n %= s;
        if (s1 < s2)
            swap(s1, s2), swap(v1, v2);
        for (long long i = 0; i <= n / s1; ++i)
        {
            long long cur = 0, m = n;
            cur += i * v1;
            m -= i * s1;
            cur += m / s2 * v2;
            best = max(best, cur); //枚举维护最大价值。
        }
        best += x; //二者相加。
        printf("Case #%d: %lld\n", ++t, best);
    }
    return 0;
}