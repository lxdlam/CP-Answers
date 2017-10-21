#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<char> res;

void init()
{
    for (int i = 0; i < 26; i++)
        res.insert(i + 'a');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    bool bef[26] = {false};
    string g, t;
    cin >> n >> g;
    vector<int> cood;
    for (int i = 0; i < g.size(); i++)
    {
        if (g[i] == '*')
            cood.emplace_back(i);
        else
            bef[g[i] - 'a'] = true;
    }
    cin >> n;
    while (n--)
    {
        cin >> t;
        set<char> s, temp;
        bool c = false;
        for (int i = 0; i < g.size(); i++)
        {
            if (g[i] == '*')
                continue;
            else if (g[i] != t[i])
            {
                c = true;
                break;
            }
        }
        for (int i = 0; i < cood.size(); i++)
        {
            if (bef[t[cood[i]] - 'a'])
            {
                c = true;
                break;
            }
            s.insert(t[cood[i]]);
        }
        if (c)
            continue;
        set_intersection(res.begin(), res.end(), s.begin(), s.end(), inserter(temp, temp.begin()));
        res = temp;
    }
    cout << res.size() << endl;
}