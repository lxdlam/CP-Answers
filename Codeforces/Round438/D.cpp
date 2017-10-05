#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

#define SUB(x, l, r) x.substr(l, r - l)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string temp;
    vector<string> v;
    set<string> s;
    map<string, int> m;
    int a, b, num;
    cin >> T;
    while (T--)
    {
        cin >> temp;
        v.emplace_back(temp);
    }
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        temp = v[a - 1] + v[b - 1];
        v.emplace_back(temp);
        m[temp] = max(m[v[a - 1]], m[v[b - 1]]);
        for (int i = m[temp] + 1;; i++)
        {
            s.clear();
            num = pow(2, i);
            for (int j = 0; j <= temp.size() - i; j++)
            {
                s.insert(SUB(temp, j, j + i));
                //cout<<j<<endl;
                if (s.size() == num)
                    break;
            }
            if (s.size() < num)
                break;
            m[temp] = i;
        }
        cout << m[temp] << endl;
    }
    return 0;
}