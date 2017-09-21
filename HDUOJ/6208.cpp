#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const string &a, const string &b)
    {
        return a.length() >= b.length();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<string, cmp> s;
    string temp;
    int T, t;
    bool flag;
    cin >> T;
    while (T--)
    {
        flag = true;
        cin >> t;
        while (t--)
        {
            cin >> temp;
            s.insert(temp);
        }
        set<string, cmp>::iterator it = s.begin();
        temp = *it;
        for (; it != s.end(); it++)
        {
            if (temp.find(*it) == string::npos)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << temp << endl;
        else
            cout << "No" << endl;
        s.clear();
    }
    return 0;
}