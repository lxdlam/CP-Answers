#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int a, b, c;
    string t;
    cin >> a >> b >> c >> t;
    v.emplace_back(a);
    v.emplace_back(b);
    v.emplace_back(c);

    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++)
    {
        if (t[i] == 'A')
            cout << v[0] << " ";
        else if (t[i] == 'B')
            cout << v[1] << " ";
        else if (t[i] == 'C')
            cout << v[2] << " ";
    }
    cout << endl;

    return 0;
}