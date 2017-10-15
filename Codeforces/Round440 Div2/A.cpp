#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m;
    set<int> s1, s2;
    while (n--)
    {
        cin >> t;
        s1.insert(t);
    }
    while (m--)
    {
        cin >> t;
        s2.insert(t);
    }
    for (auto i : s1)
    {
        for (auto j : s2)
            if (i == j)
            {
                cout << i << endl;
                return 0;
            }
    }
    int n1 = *(s1.begin()), n2 = *(s2.begin());
    if (n1 > n2)
        cout << n2 << n1 << endl;
    else
        cout << n1 << n2 << endl;
    return 0;
}