#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 26 + 10;

int ti[SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string t;
    cin >> t;
    for (int i = 0; i < 26; i++)
        cin >> ti[i];

    int res = 0;

    for (auto i : t)
        res += ti[i - 'a'];

    cout << res << endl;

    return 0;
}