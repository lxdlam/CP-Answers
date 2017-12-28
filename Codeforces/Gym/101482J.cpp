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

    multiset<string> d, k;
    vector<string> r;
    int n;
    string t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        d.insert(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        k.insert(t);
    }

    set_intersection(d.begin(), d.end(), k.begin(), k.end(), inserter(r, r.begin()));

    cout << r.size() << endl;

    return 0;
}