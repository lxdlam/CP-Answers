#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{

    vector<int> v;
    int T, t;
    cin >> T;
    while (T--)
    {
        cin >> t;
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    auto now = chrono::system_clock::now();
    int64_t d;
    do
    {
        d = duration_cast<milliseconds>(system_clock::now() - now).count();
    } while (d < 1205);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}