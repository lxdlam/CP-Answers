#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string a;
    set<char> s;
    cin >> a;
    for (int i = 0; i < a.size() - 1; i++)
        s.insert(a[i]);
    cout << s.size() << endl;
    return 0;
}