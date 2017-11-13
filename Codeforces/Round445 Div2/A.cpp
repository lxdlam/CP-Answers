#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(6);
    int sum = 0;

    for (auto &i : v)
    {
        cin >> i;
        sum += i;
    }
    sort(v.begin(), v.end());

    bool flag = false;

    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            for (int k = j + 1; k < 6; k++)
                if ((v[i] + v[j] + v[k]) * 2 == sum)
                    flag = true;

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}