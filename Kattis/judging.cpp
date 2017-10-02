#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> k, d;
    set<string> s;
    int res = 0;
    int T;
    string temp;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        s.insert(temp);
        d[temp]++;
    }
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        s.insert(temp);
        k[temp]++;
    }
    for (auto i : s)
    {
        res += min(k[i], d[i]);
    }
    cout << res << endl;
    return 0;
}