#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 2e5 + 10;

vector<int> res[SIZE];
int big[SIZE] = {0};

int bs(int len, int k)
{
    if (len <= 0 || big[len - 1] > k)
        return -1;
    int res = 0, l = 0, r = len - 1;
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (big[m] < k)
        {
            res = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num = 0, T, t;
    bool flag;
    cin >> T;
    while (T--)
    {
        flag = false;
        cin >> t;
        int s = bs(num, t);
        //cout << "Search pos: " << s << endl;
        if (s == -1)
        {
            res[num].emplace_back(t);
            big[num++] = t;
        }
        else
        {
            res[s].emplace_back(t);
            big[s] = t;
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (auto i : res[i])
            cout << i << " ";
        cout << endl;
    }
    return 0;
}