#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

ll solve(const string &num)
{
    ll ans = num[0] - '0';

    for (int i = 1; i < num.size(); i++)
    {
        ans <<= 1;
        ans += (ans >> 1 & 1) ^ (num[i] - '0');
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string a, b;
    cin >> n >> a >> b;
    cout << solve(b) - solve(a) - 1 << endl;
    return 0;
}