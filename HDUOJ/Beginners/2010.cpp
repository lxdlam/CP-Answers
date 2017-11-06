#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num[] = {153, 370, 371, 407};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    vector<int> v;
    while (cin >> l >> r)
    {
        v.clear();
        for (int i = 0; i < 4; i++)
        {
            if (num[i] <= r && num[i] >= l)
                v.push_back(num[i]);
        }
        if (v.empty())
            cout << "no";
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (i == 0)
                    cout << v[i];
                else
                    cout << " " << v[i];
            }
        }
        cout << endl;
    }

    return 0;
}