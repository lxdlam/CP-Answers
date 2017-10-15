#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n, k, t;
    cin >> n >> k;
    vector<long> v;
    while (n--)
    {
        cin >> t;
        v.emplace_back(t);
    }
    long l = v[0], r = v[v.size() - 1];
    sort(v.begin(), v.end());
    long i = v[0], j = v[v.size() - 1];
    if (k == 1)
    {
        cout << i << endl;
    }
    else if (k == 2)
    {
        cout << (l > r ? l : r) << endl;
    }
    else if (k > 2)
    {
        cout << j << endl;
    }
    return 0;
}