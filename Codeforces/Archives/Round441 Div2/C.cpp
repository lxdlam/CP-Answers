#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long q, k, m;
    cin >> q;
    vector<int> res;
    for (long i = q - 81 > 0 ? q - 81 : 1; i < q; i++)
    {
        k = m = i;
        while (m)
        {
            k += m % 10;
            m /= 10;
        }
        if (k == q)
            res.emplace_back(i);
    }

    cout << res.size() << endl;
    if (res.size() != 0)
        for (auto i : res)
            cout << i << endl;

    return 0;
}