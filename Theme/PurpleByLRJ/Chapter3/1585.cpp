#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    string t;
    int count;
    int sum;
    while (T--)
    {
        count = 0;
        sum = 0;
        cin >> t;
        for (auto i : t)
        {
            if (i == 'O')
            {
                sum++;
                count += sum;
            }
            else if (i == 'X')
                sum = 0;
        }
        cout << count << endl;
    }
    return 0;
}