#include <iostream>
#include <vector>
#include <string>

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

// j is the longest suffix length
int match(const string &t, const string &p)
{
    int count = 0;
    int j = 0;
    vector<int> next;
    getNext(p, next);
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
    }
    return j == -1 ? 0 : j;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string a, b;
    while (cin >> a >> b)
    {
        int la = match(a, b);
        int lb = match(b, a);
        if (la > lb || (la == lb && a <= b))
        {
            cout << a;
            cout << b.substr(la, b.size() - la) << endl;
        }
        else
        {
            cout << b;
            cout << a.substr(lb, a.size() - lb) << endl;
        }
    }
    return 0;
}