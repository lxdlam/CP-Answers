#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string t;
    set<char> s;
    s.insert('a');
    s.insert('e');
    s.insert('i');
    s.insert('o');
    s.insert('u');
    cin >> t;
    int cnt = 0;
    for (auto i : t)
    {
        if (s.count(i))
            cnt++;
        else if (isdigit(i) && ((i - '0') & 1))
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}