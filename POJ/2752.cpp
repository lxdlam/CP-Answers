#include <iostream>
#include <vector>
#include <string>
#include <set>

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

int main()
{
    string a;
    vector<int> next;
    set<int> s;
    while (cin >> a)
    {
        next.clear();
        s.clear();
        getNext(a, next);
        int i = a.length();
        while (next[i] != 0)
        {
            s.insert(next[i]);
            i = next[i];
        }
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++)
            cout << *it << " ";
        cout << a.length() << endl;
    }
    return 0;
}