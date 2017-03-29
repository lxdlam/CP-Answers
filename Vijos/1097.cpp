#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, temp;
    long ans = 0;
    vector<int> v;
    cin >> n;
    while (cin >> temp)
        v.push_back(temp);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (!i)
            ans += v[i] * (n - 1);
        else
            ans += v[i] * n;
        n--;
    }
    v.clear();
    cout << ans << endl;
    return 0;
}