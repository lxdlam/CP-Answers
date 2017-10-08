#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> m;
    int n, t, q;
    while (cin >> n && n != 0)
    {
        m.clear();
        while (n--)
        {
            cin >> t;
            m[t]++;
        }
        cin >> q;
        cout << m[q] << endl;
    }
    return 0;
}