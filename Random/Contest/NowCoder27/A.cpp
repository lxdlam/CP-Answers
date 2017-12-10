#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

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
    int T, t, n;
    si s;
    cin >> T;
    while (T--)
    {
        cin >> n;
        s.clear();
        while (n--)
        {
            cin >> t;
            s.insert(t);
        }
        cout << s.size() << endl;
    }
    return 0;
}