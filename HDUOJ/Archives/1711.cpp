#include <iostream>
#include <vector>

using namespace std;

void getNext(vector<int> &s, int next[])
{
    int j;
    j = next[0] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j])
            j = next[j];
        next[i + 1] = ++j;
    }
}

int match(vector<int> &t, vector<int> &p)
{
    int next[(int)(1e5 + 10)];
    int j;
    j = 0;
    getNext(p, next);
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && t[i] != p[j])
            j = next[j];
        j++;
        if (j == p.size())
        {
            return i - j + 2;
            j = next[j];
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, temp;
    int n, m;
    vector<int> t, p;
    cin >> T;
    while (T--)
    {
        t.clear();
        p.clear();
        cin >> n >> m;
        while (n--)
        {
            cin >> temp;
            t.push_back(temp);
        }
        while (m--)
        {
            cin >> temp;
            p.push_back(temp);
        }
        cout << match(t, p) << endl;
    }
    return 0;
}