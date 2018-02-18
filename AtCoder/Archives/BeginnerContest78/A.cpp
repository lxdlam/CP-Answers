#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num(char n)
{
    return isdigit(n) ? n - '0' : n - 'A' + 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char a, b;
    cin >> a >> b;
    if (num(a) < num(b))
        cout << '<' << endl;
    else if (num(a) > num(b))
        cout << '>' << endl;
    else
        cout << '=' << endl;
    return 0;
}