#include <iostream>
#include <set>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<string> s;
    int T;
    string t;
    cin >> T;
    while (T--)
    {
        cin >> t;
        if (s.count(t) == 0)
        {
            cout << "NO" << endl;
            s.insert(t);
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}