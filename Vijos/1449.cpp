#include <iostream>
#include <string>

using namespace std;

string reverse(string);
bool check(string, string, string);

int main()
{
    string a, b, c;
    int n;
    cin >> n;
    cin >> a >> b >> c;
}

string reverse(string src)
{
    string res = "";
    for (auto it = src.begin(); it != src.end(); it++)
        res += *it;
    return res;
}