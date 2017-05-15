#include <vector>
#include <iostream>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main()
{
    vector<int> v;
    int m, max, x, y, sum, p, t;
    while (cin >> m && m != 0)
    {
        v.clear();
        max = -10000;
        sum = x = y = p = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            v.push_back(t);
        }
        for (int i = 0; i < m; i++)
        {
            sum += v[i];
            if (sum > max)
            {
                max = sum;
                x = p;
                y = i;
            }
            if (sum < 0)
            {
                sum = 0;
                p = i + 1;
            }
        }
        if (max >= 0)
            cout << max << " " << v[x] << " " << v[y] << endl;
        else
            cout << "0 " << v[0] << " " << v[v.size() - 1] << endl;
    }
    return 0;
}