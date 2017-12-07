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
    double g1, g2, p1, p2;
    cin >> g1 >> p1 >> g2 >> p2;
    p2++;
    cout << min((int)(g2 - g1), (int)(ceil(g2 * p2 / 100) - ceil(g1 * p1 / 100) - 1)) << endl;
    return 0;
}