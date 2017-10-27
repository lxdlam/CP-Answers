#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i;
    int s, d;
    int res = 0;
    cin >> n;
    while (n--)
    {
        cin >> s >> d;
        for (i = 0; s + i * d <= res; i++)
            ;
        res = s + i * d;
    }
    cout << res << endl;
    return 0;
}