#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<string> split(const string &s)
{
    vector<string> res;
    int i = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        if (s[pos] == '1')
        {
            res.push_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    res.push_back(s.substr(i, s.size() - i));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, r, res;
    cin >> n >> k;
    string t;
    cin >> t;

    vector<string> v = split(t);

    res = l = r = 0;

    for (string i : v)
        res = max(res, (int)i.size());

    if (t[0] == '0')
        l = v[0].size();
    if (t[n - 1] == '0')
        r = v[v.size() - 1].size();

    if (v.size() == 1)
        cout << v[0].size() * k << endl;
    else if (v.size() == 0)
        cout << 0 << endl;
    else if (k == 1)
        cout << res << endl;
    else
        cout << max(res, l + r) << endl;

    return 0;
}