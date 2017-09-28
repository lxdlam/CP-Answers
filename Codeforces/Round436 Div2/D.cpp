#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 200000 + 10;

int times[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        times[i] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    vector<int> v;
    int T, t, count = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> t;
        times[t]++;
        v.push_back(t);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (times[v[i]] > 1)
        {
            for (int j = 1; j < SIZE; j++)
            {
                if (times[j] == 0 && j > i)
                {
                    times[v[i]]--;
                    v[i] = j;
                    times[j] = 1;
                    count++;
                    break;
                }
                else if (times[j] == 0)
                    break;
            }
        }
    }
    cout << count << endl;
    for (auto i : v)
        cout << i << " ";
    return 0;
}