#include <set>
#include <iostream>

using namespace std;

int main()
{
    set<int> s;
    int n, x;
    int t;
    int res = 0, count = 0;
    cin >> n >> x;
    while (n--)
    {
        cin >> t;
        if (t == x)
            count = -1;
        s.insert(t);
    }
    s.insert(x);
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it < x)
            count++;
        if (*it == x)
            break;
    }
    cout << x - count << endl;
}