#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    int i, j, count;
    int sa, sb;
    while (cin >> a >> b)
    {
        i = j = count = 0;
        sa = a.size();
        sb = b.size();
        while (true)
        {
            if (i == sa || j == sb)
                break;
            if (a[i] == b[j])
            {
                count++;
                i++;
            }
            j++;
        }
        if (count == sa)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
