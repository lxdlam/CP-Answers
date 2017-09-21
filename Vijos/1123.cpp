#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, T;
    vector<int> v;
    int sum = 0, ave;
    int count = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> t;
        sum += t;
        v.push_back(t);
    }
    ave = sum / T;
    for (int i = 0; i < T - 1; i++)
    {
        if (v[i] != ave)
        {
            v[i + 1] += v[i] - ave;
            v[i] = ave;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}