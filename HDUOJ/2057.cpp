#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

inline ll converter(char num)
{
    if (num >= '0' && num <= '9')
        return num - '0';
    else
        return num - 'A' + 10;
}

inline char converter(ll num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num - 10 + 'A';
}

string tohex(ll num)
{
    if (num == 0)
        return "0";
    string s;
    bool ne = num < 0 ? true : false;
    num = abs(num);
    while (num)
    {
        s.push_back(converter(num % 16));
        num /= 16;
    }
    reverse(s.begin(), s.end());
    return (ne ? "-" : "") + s;
}

ll todec(string num)
{
    if (num[0] == '+' || num[0] == '-')
    {
        ll res = 0;
        for (ll i = 1; i < num.size(); i++)
        {
            res *= 16;
            res += converter(num[i]);
        }

        return num[0] == '-' ? -res : res;
    }
    else
    {
        ll res = 0;
        for (ll i = 0; i < num.size(); i++)
        {
            res *= 16;
            res += converter(num[i]);
        }

        return res;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    while (cin >> a >> b)
        cout << tohex(todec(a) + todec(b)) << endl;
    return 0;
}