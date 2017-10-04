#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, string> m;
    string o, n;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> o >> n;
        if (!m.count(o))
            m[o] = o;
        m[n] = m[o];
        m.erase(o);
    }
    cout << m.size() << endl;
    for (auto i : m)
    {
        cout << i.second << " " << i.first << endl;
    }
    return 0;
}