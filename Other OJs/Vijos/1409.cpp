#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    int max;
    int temp;
    int count = 0;
    cin >> max >> n;
    while (n--)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    temp = 0;
    while (true)
    {
        while (v[temp] + v[v.size() - 1] > max)
        {
            count++;
            v.pop_back();
        }
        count++;
        if (v.size() == 0)
            break;
        v.erase(v.begin());
        if (v.size() == 0)
            break;
        v.pop_back();
        if (v.size() == 0)
            break;
    }
    cout << count << endl;
    return 0;
}