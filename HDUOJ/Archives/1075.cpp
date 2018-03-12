#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, string> m;
    string s, t;
    char pu;
    bool p;
    cin >> s;
    while (cin >> s && s != "END")
    {
        cin >> t;
        m[t] = s;
    }
    cin >> s;
    cin.get();
    while (getline(cin, s) && s != "END")
    {
        t.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] > 'z' || s[i] < 'a')
            {
                if (!t.empty())
                {
                    if (m.count(t) != 0)
                        cout << m[t];
                    else
                        cout << t;
                    t.clear();
                }
                cout << s[i];
            }
            else
                t += s[i];
        }
        cout << endl;
    }
    return 0;
}