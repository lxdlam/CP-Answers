#include <iostream>

using namespace std;

const int SIZE = 110;

int pre[110] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    bool follow = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    int t = pre[0] - pre[1];
    for (int i = 1; i < n - 1; i++)
    {
        if (pre[i] - pre[i + 1] != t)
        {
            follow = false;
            break;
        }
    }
    if (follow)
        cout << pre[n - 1] - t << endl;
    else
        cout << pre[n - 1] << endl;
    return 0;
}