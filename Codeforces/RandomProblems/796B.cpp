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

    int n, m, k, t;
    int h1, h2;
    int bone = 1;
    si s;
    cin >> n >> m >> k;
    while (m--)
    {
        cin >> t;
        s.insert(t);
    }
    while (k--)
    {
        if (s.count(bone))
            break;
        cin >> h1 >> h2;
        if (h1 == bone)
            bone = h2;
        else if (h2 == bone)
            bone = h1;
    }

    cout << bone << endl;

    return 0;
}