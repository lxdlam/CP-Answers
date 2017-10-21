#include <iostream>
#include <vector>

using namespace std;

vector<int> v = {0, 0, 0, 0, 0, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        for (int i = 0; i < 7; i++)
        {
            v[i] += t % 10;
            t /= 10;
        }
    }
    int res = 0;
    for (auto i : v)
        res = max(res, i);
    cout << res << endl;
    return 0;
}