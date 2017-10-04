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
    int T;
    int count = 0, len;
    while (cin >> T && T != 0)
    {
        next.clear();
        cin >> a;
        getNext(a, next);
        len = next.size();
        cout << "Test case #" << ++count << endl;
        for (int i = 2; i < len; i++)
        {
            if (i % (i - next[i]) == 0 && next[i] > 0)
            {
                cout << i << " " << i / (i - next[i]) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}