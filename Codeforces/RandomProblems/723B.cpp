#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int size;
    string s;
    cin >> size >> s;
    int in = 0, mout = 0, t = 0;
    bool c = false, p = false;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '_')
        {
            c = false;
            t = 0;
        }
        if (s[i] == '(')
            p = true;
        else if (s[i] == ')')
            p = false;
        else if (s[i] != '_')
        {
            if (!p && !c)
            {
                c = true;
                t++;
            }
            else if (!p && c)
                t++;
            else if (p && !c)
            {
                c = true;
                in++;
            }
        }
        mout = max(mout, t);
    }
    cout << mout << " " << in << endl;
    return 0;
}