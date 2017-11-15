#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    cin >> T;
    string s1, s2, s12, res;
    int times;
    for (int i = 1; i <= T; i++)
    {
        cout << i << " ";
        times = 0;
        s1.clear();
        s2.clear();
        s12.clear();
        cin >> n >> s1 >> s2 >> s12;
        res = s12;

        while (++times)
        {
            res = s12;
            for (int i = 0; i < n; i++)
            {
                res[2 * i] = s2[i];
                res[2 * i + 1] = s1[i];
            }
            if (s12 == res)
                break;
            else if ((n - 1) * 2 < times)
            {
                times = -1;
                break;
            }
            s1 = res.substr(0, n);
            s2 = res.substr(n, n);
        }

        cout << times << endl;
    }
    return 0;
}