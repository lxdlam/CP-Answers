#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> s;
    string t;

    while (getline(cin, t) && t != "#")
    {
        s.clear();
        stringstream ss(t);
        while (ss >> t)
            s.insert(t);
        cout << s.size() << endl;
    }

    return 0;
}