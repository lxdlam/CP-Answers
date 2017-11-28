#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> v = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
vector<vector<int>> nexts;

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

int match(const string &t, const string &p, vector<int> &next)
{
    int count = 0;
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
        if (j == p.size())
        {
            //matched, change behavior here
            count++;
            j = next[j]; // important, start a new match process
        }
    }
    return count;
}

void init()
{
    nexts.resize(5);
    for (int i = 0; i < 5; i++)
        getNext(v[i], nexts[i]);
}

bool solve(const string &s)
{
    int res = 0;
    for (int i = 0; i < 5; i++)
        res += match(s, v[i], nexts[i]);
    return res == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    string t;
    cin >> t;
    if (solve(t))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}