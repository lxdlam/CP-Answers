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
    for (int i = 0; i < v.size(); i++)
    {
        temp += v[i];
        if (temp >= max)
        {
            temp = v[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}