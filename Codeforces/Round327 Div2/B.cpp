#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int MAX = 2e6 + 10;

char ch[26] = {'a'};
int res[MAX] = {0};

void init()
{
    for (int i = 1; i < 26; i++)
    {
        ch[i] = ch[i - 1] + 1;
    }
}

int main()
{
    init();
    string str;
    int n, m;
    char a, b;
    cin >> n >> m >> str;
    for (int i = 0; i < n; i++)
    {
        res[i] = str[i] - 'a';
    }
    while (m--)
    {
        cin >> a >> b;
        for (int i = 0; i < 26; i++)
        {
            if (ch[i] == a)
                ch[i] = b;
            else if (ch[i] == b)
                ch[i] = a;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ch[res[i]];
    return 0;
}