#include <map>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<long> res;
    map<long, vector<long>> re;
    int n, k, m;
    long t;
    bool flag = false;
    cin >> n >> k >> m;

    while (n--)
    {
        cin >> t;
        re[t % m].emplace_back(t);
    }
    for (auto i : re)
    {
        if (i.second.size() >= k)
        {
            flag = true;
            res = i.second;
        }
    }
    if (!flag)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (auto i : res)
        {
            cout << i << " ";
            if (--k == 0)
                break;
        }
        cout << endl;
    }

    return 0;
}