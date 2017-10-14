#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void getNext(const string &s, vi &next)
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
    int count = 0;
    int j = 0;
    vector<int> next;
    getNext(p, next);
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
        if (j == p.size())
        {
            //matched, change behavior here
            count++;
            j = next[j]; // important, start new match process
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t, p;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> t >> p;
        cout << "Case " << i << ": " << match(t, p) << endl;
    }
    return 0;
}