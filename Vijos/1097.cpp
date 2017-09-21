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
    while (true)
    {
        sort(v.begin(), v.end(), [](int x, int y) {
            return x > y;
        });
    }
    v.clear();
    cout << ans << endl;
    return 0;
}