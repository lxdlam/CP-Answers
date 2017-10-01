#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> split(string s)
{
    vector<string> res;
    int i = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        if (s[pos] <= 'Z' && s[pos] >= 'A')
        {
            res.push_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    res.push_back(s.substr(i, s.size() - i));
    return res;
}

int solve(string s)
{
    // bool appear[26];
    // for (auto &i : appear)
    //     i = false;
    // int count = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (!appear[s[i] - 'a'])
    //     {
    //         count++;
    //         appear[s[i] - 'a'] = true;
    //     }
    // }
    // return count;
    set<char> app;
    for (int i = 0; i < s.size(); i++)
        app.insert(s[i]);
    return app.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    int T;
    cin >> T >> t;
    int res = 0;
    vector<string> v = split(t);
    for (auto s : v)
    {
        res = max(res, solve(s));
    }
    cout << res << endl;
    return 0;
}