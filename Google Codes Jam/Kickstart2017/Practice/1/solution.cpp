#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string ans, temp;
    int n, m, count = 1, maxsize = 0;
    set<char> s;
    cin >> n;
    while (n--)
    {
        cin >> m;
        while (m--)
        {
            cin >> temp;
            for (int i = 0; i < temp.size() - 1; i++)
                s.insert(temp[i]);
            if (s.size() > maxsize)
            {
                maxsize = s.size();
                ans = temp;
            }
            else if (s.size() == maxsize)
            {
                if (ans[0] > temp[0])
                    ans = temp;
            }
            s.clear();
        }
        cout << "Case #" << count++ << ": " << ans << endl;
        maxsize = 0;
    }
    return 0;
}