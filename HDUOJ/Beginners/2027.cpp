#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

map<char, int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string t;
    cin >> n;
    cin.get();
    while (n--)
    {
        cnt.clear();
        getline(cin, t);
        for (int i = 0; i < t.size(); i++)
            cnt[t[i]]++;

        cout << "a:" << cnt['a'] << endl;
        cout << "e:" << cnt['e'] << endl;
        cout << "i:" << cnt['i'] << endl;
        cout << "o:" << cnt['o'] << endl;
        cout << "u:" << cnt['u'] << endl;
        if (n != 0)
            cout << endl;
    }
    return 0;
}