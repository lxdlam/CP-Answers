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
    int T;
    int n, m, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        n %= m;
        if (n == 0 || n + k >= m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}