#include <bits/stdc++.h>

using namespace std;

void getNext(const string &s, vector<int> &next)
{
    int j = -1;
    next.push_back(-1);
    for (int i = 0; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j])
            j = next[j];
        next.push_back(++j);
    }
}

int match(const string &t, const string &p)
{
    //change size here
    int count = 0;
    int j = 0;
    vector<int> next;
    getNext(p, next);
    for (int i = 0; i < t.size();)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
        if (j == p.size())
        {
            //matched, change behavior here
            count++;
            j = 0; // important, start new match process
            //i += j;
            //continue;
        }
        i++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t, p;
    while (cin >> t && t != "#")
    {
        cin >> p;
        cout << match(t, p) << endl;
    }
    return 0;
}