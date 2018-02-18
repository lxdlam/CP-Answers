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

    int a, b;
    cin >> a >> b;
    int t = (a * 10 + b * 10) / 2;
    if (t % 10 >= 5)
        t = t / 10 + 1;
    else
        t /= 10;
    cout << t << endl;

    return 0;
}