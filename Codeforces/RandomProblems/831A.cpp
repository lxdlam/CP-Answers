#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    bool flag = true;
    int T, t, p1, p2;
    cin >> T;
    while (T--)
    {
        cin >> t;
        v.emplace_back(t);
    }
    p1 = 0;
    p2 = v.size() - 1;
    while (true)
    {
        p1++;

        if (v[p1] <= v[p1 - 1])
        {
            p1--;
            break;
        }
    }
    while (true)
    {
        p2--;
        if (v[p2] <= v[p2 + 1])
        {
            p2++;
            break;
        }
    }
    for (; p1 <= p2 && flag; p1++)
    {
        if (v[p1] != v[p2])
            flag = false;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}