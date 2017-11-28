#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int last[26];
int ans[26] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t;
    int res = 1e5 + 10;
    cin >> t;
    int len = t.size();
    for (int i = 0; i < 26; i++)
        last[i] = -1;
    for (int i = 0; i < len; i++)
    {
        ans[t[i] - 'a'] = max(i - last[t[i] - 'a'], ans[t[i] - 'a']);
        last[t[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++)
        ans[i] = max(ans[i], len - last[i]);

    for (int i = 0; i < 26; i++)
        if (last[i] != -1)
            res = min(ans[i], res);

    cout << res << endl;

    return 0;
}