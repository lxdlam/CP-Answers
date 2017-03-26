#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    string a;
    int count = 0, ans, all;
    cin >> all;
    cin.get();
    while (all--)
    {
        count++;
        ans = 10000;
        cin >> a;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[i] == a[j])
                    ans = ans > j - i ? j - i : ans;
            }
        }
        if (ans == 10000)
            ans = -1;
        cout << "Case #" << count << ": " << ans << endl;
    }
    return 0;
}