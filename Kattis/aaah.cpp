#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.length() >= b.length())
        cout << "go" << endl;
    else
        cout << "no" << endl;
    return 0;
}