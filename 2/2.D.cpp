#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, s1, v1, s2, v2, ans, mv;
    int count = 0, all;
    cin >> all;
    cin.get();
    while (all--)
    {
        count++;
        ans = 0;
        cin >> n >> s1 >> v1 >> s2 >> v2;
        mv = n / (s1 * s2) * max(s2 * v1, s1 * v2);
        n %= s1 * s2;
        if (s2 > s1)
        {
            swap(s1, s2);
            swap(v1, v2);
        }
        for (long long i = 0; i <= n / s1; i++)
        {
            long long now = i * v1, ls = n - i * s1;
            now += ls / s2 * v2;
            ans = max(ans, now);
        }
        cout << "Case #" << count << ": " << ans + mv << endl;
    }
    return 0;
}