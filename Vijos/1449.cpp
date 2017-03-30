#include <iostream>
#include <string>

using namespace std;

string reverse(string);
bool check(string, string);

int main()
{
    string a, b, c;
    int n;
    cin >> n;
    cin >> a >> b >> c;
    if (check(a, b))
        cout << reverse(c) << endl;
    else if (check(b, c))
        cout << reverse(a) << endl;
    else
        cout << reverse(b) << endl;
    return 0;
}

string reverse(string src)
{
    string res = "";
    for (int i = src.size() - 1; i >= 0; i--)
        res += src[i];
    return res;
}