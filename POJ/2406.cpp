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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> next;
    string a;
    int len;
    while (cin >> a && a != ".")
    {
        next.clear();
        getNext(a, next);
        len = a.size();
        // s1b
        if (len % (len - next[len]) == 0)
            cout << len / (len - next[len]) << endl;
        else
            cout << "1" << endl;
    }
    cout << endl;
    return 0;
}