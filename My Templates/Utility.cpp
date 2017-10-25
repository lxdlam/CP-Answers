#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s)
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

string reverse(const string &s)
{
    string res = s;
    reverse(res.begin(), res.end());
    return res;
}