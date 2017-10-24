// not solved
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> as, bs;
    int res = 0, a = 0, b = 0;
    string s;
    cin >> s;
    int n = s.size();
    as.resize(n);
    bs.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a++;
        else if (s[i] == 'b')
            b++;
        as[i] = a;
        bs[i] = b;
    }

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            res = max(res, as[n - 1] - as[j] + bs[j] - bs[i] + as[i]);

    cout << res << endl;

    return 0;
}