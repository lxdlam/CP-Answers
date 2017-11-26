#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = 0, b = 0, c = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a++;
            c++;
        }
        if (s[i] == 'b')
            b++;
        a = max(a, b);
        b = max(b, c);
    }

    cout << a << endl;

    return 0;
}