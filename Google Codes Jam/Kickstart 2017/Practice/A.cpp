#include <iostream>
#include <set>

using namespace std;

int main()
{
    string temp;
    string res;
    set<char> s;
    int T, n, ms;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        ms = 0;
        res.clear();
        cin >> n;
        getchar();
        cout << "Case #" << i << ": ";
        while (n--)
        {
            s.clear();
            getline(cin, temp, '\n');
            for (int j = 0; j < temp.size(); j++)
                if (temp[j] != ' ')
                    s.insert(temp[j]);
            if (s.size() > ms || (s.size() == ms && temp <= res))
            {
                res = temp;
                ms = s.size();
            }
        }
        cout << res << endl;
    }
    return 0;
}