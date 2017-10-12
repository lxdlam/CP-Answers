// Figure it out
// Source: http://blog.csdn.net/zhang_di233/article/details/48108347
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100000 + 10;

int pos[SIZE * 2];

void init()
{
    for (auto &i : pos)
        i = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int s, len = 0, res = 0;
    string t;
    cin >> s >> t;
    for (int i = 0; i < s; i++)
    {
        if (t[i] == '1')
            len++;
        else if (t[i] == '0')
            len--;
        if (len == 0)
        {
            res = max(res, i + 1);
            continue;
        }
        if (pos[len + SIZE] == -1)
            pos[len + SIZE] = i;
        else
            res = max(res, i - pos[len + SIZE]);
    }
    cout << res << endl;
    return 0;
}