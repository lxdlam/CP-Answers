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
    int h1, a1, c1;
    int h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> v;
    while (true)
    {
        if (h2 <= 0)
            break;
        // Vova's Round
        if (h1 - a2 <= 0 && h2 - a1 > 0)
        {
            h1 += c1;
            v.emplace_back("HEAL");
        }
        else
        {
            h2 -= a1;
            v.emplace_back("STRIKE");
        }
        h1 -= a2;
    }
    cout << v.size() << endl;
    for (auto i : v)
        cout << i << endl;

    return 0;
}