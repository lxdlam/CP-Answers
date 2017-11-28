#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, pos;
    cin >> n;
    int res = 0;
    vector<int> p(n);

    for (auto &i : p)
        cin >> i; // means that the i people before him will die

    pos = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < pos) // i not in the range of who will die
            res++;
        pos = min(pos, i - p[i]); // the edge
    }

    cout << res << endl;

    return 0;
}