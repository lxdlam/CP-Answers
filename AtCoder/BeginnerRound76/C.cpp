#include <bits/stdc++.h>

using namespace std;

vector<int> match(const string &t, const string &p)
{
    vector<int> res;
    bool find;
    for (int i = 0; i < t.size(); i++)
    {
        find = false;
        if (t[i] == '?' || t[i] == p[0])
        {
            for (int j = 1; j < p.size(); j++)
            {
                if (t[i + j] != '?' && t[i + j] != p[j])
                {
                    find = true;
                    break;
                }
            }
            if (!find)
                res.push_back(i);
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t, p, temp, res;
    cin >> t >> p;
    vector<int> poss = match(t, p);
    if (poss.size() != 0)
    {
        res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        for (auto pos : poss)
        {
            temp = t;
            for (int i = 0; i < p.size(); i++)
                temp[pos + i] = p[i];
            for (auto &i : temp)
                if (i == '?')
                    i = 'a';
            res = min(res, temp);
        }
    }
    else
        res = "UNRESTORABLE";
    cout << res << endl;
    return 0;
}