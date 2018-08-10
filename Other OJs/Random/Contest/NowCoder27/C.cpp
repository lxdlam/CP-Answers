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

ll Palind[1000000], pnum = 1;

void init()
{
    ll n, m, k, p, q, r;
    for (n = 1; n <= 9; n++)
        for (m = 0; m <= 9; m++)
            for (k = 0; k <= 9; k++)
                for (p = 0; p <= 9; p++)
                    Palind[pnum++] = 10000001 * n + 1000010 * m + 100100 * k + 11000 * p;
    //Palind[pnum++] = 100000000001ll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    for (int i = 1; i < pnum; i++)
        cout << Palind[i] << endl;

    return 0;
}