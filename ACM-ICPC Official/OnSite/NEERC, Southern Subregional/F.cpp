#include <iostream>
#include <set>

using namespace std;

string process(string str)
{
    string res;
    int pos, count;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != 'k' && str[i] != 'u' && str[i] != 'o')
            res += str[i];
        if (str[i] == 'k')
        {
            pos = i;
            while (i < str.size())
            {
                i++;
                if (str[i] != 'k')
                    break;
            }
            if (i == str.size() || str[i] != 'h')
            {
                i = pos;
                res += str[i];
            }
            else
                i--;
        }
        if (str[i] == 'u' || str[i] == 'o')
        {
            count = 0;
            i--;
            while (str.size() > i || i == -1)
            {
                i++;
                if (str[i] == 'u')
                    count += 2;
                else if (str[i] == 'o')
                    count += 1;
                else
                    break;
            }
            i--;
            if (count % 2)
            {
                res += 'o';
                count--;
            }
            while (count > 0)
            {
                res += 'u';
                count -= 2;
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string t;
    cin >> T;
    set<string> s;
    while (T--)
    {
        cin >> t;
        s.insert(process(t));
    }
    cout << s.size() << endl;
    return 0;
}