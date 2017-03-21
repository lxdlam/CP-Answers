#include <iostream>
#include <set>

using namespace std;

int main()
{
    int m, n, temp;
    set<int> s;
    while (cin >> m >> n)
    {
        s.clear();
        while (m--)
        {
            cin >> temp;
            s.insert(temp);
        }
        while (n--)
        {
            cin >> temp;
            s.insert(temp);
        }
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++)
        {
            if (it == s.begin())
                cout << *it;
            else
                cout << ' ' << *it;
        }
        cout << endl;
    }
    return 0;
}