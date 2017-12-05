#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int l, r;
    char c1, c2;
    while (m--)
    {
        cin >> l >> r >> c1 >> c2;
        for (l = l - 1; l < r; l++)
            if (s[l] == c1)
                s[l] = c2;
    }
    cout << s << endl;
    return 0;
}