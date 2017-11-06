#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool flag;
int n;

void dfs(ull res, int dp)
{
    if (dp == 19 || flag)
        return;
    if (res % n == 0)
    {
        flag = true;
        cout << res << endl;
        return;
    }
    dfs(res * 10, dp + 1);
    dfs(res * 10 + 1, dp + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n && n != 0)
    {
        flag = false;
        dfs(1, 0);
    }

    return 0;
}