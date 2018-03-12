#include <iostream>
#include <string>

using namespace std;

string reverse(string src)
{
    string res = "";
    for (int i = src.size() - 1; i >= 0; i--)
        res += src[i];
    return res;
}

int main()
{
    string a, b, c;
    int n;
    cin >> n;
    cin >> a >> b >> c;
    if ((a[0] - reverse(b)[0] + c[0] - reverse(b)[0]) % 26 == 0)
        cout << reverse(b) << endl;
    else if ((a[0] - reverse(c)[0] + b[0] - reverse(c)[0]) % 26 == 0)
        cout << reverse(c) << endl;
    else
        cout << reverse(a) << endl;
    return 0;
}