#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> pos;
    int s, len = 0, res = 0;
    string t;
    cin >> s >> t;
    for (int i = 0; i < s; i++)
    {
        if (t[i] == '1')
            len++;
        else if (t[i] == '0')
            len--;
        if (len == 0)
        {
            res = max(res, i + 1);
            continue;
        }
        if (pos.count(len))
            res = max(res, i - pos[len]);
        else
            pos[len] = i;
    }
    cout << res << endl;
    return 0;
}