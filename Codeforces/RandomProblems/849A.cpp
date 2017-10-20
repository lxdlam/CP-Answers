#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int res = 0;
    for (auto i : v)
        if (i % 2)
            res++;
    if (v[0] % 2 == 0 || v[n - 1] % 2 == 0)
        cout << "No" << endl;
    else if ((2 * res - n) % 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}