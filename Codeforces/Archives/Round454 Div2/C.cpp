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

    int T;
    char op;
    int cnt = 0;
    string s;
    char ans = '=';
    bool flag = false;
    set<char> ss;
    cin >> T;
    T--;
    cin >> op >> s;
    for (auto i : s)
        ss.insert(i);
    while (T--)
    {
        cin >> op >> s;
        if (flag)
        {
            if (op == '?' && s[0] != ans)
                cnt++;
            else if (op == '!')
                cnt++;
            continue;
        }
        else
        {
            if (op == '!')
            {
                set<char> tmp;
                for (auto i : s)
                    if (ss.count(i))
                        tmp.insert(i);
                ss = tmp;
            }
            if (op == '.')
                for (auto i : s)
                    ss.erase(i);
            if (op == '?')
                ss.erase(s[0]);
            if (ss.size() == 1)
            {
                ans = *ss.begin();
                flag = true;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}