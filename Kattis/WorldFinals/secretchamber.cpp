#include <iostream>
#include <string>

using namespace std;

const int SIZE = 26;

bool trans[SIZE][SIZE];

void init()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == j)
                trans[i][j] = true;
            else
                trans[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    char from, to;
    int n, m;
    string a, b;
    bool flag;
    cin >> n >> m;
    while (n--)
    {
        cin >> from >> to;
        trans[from - 'a'][to - 'a'] = true;
    }
    // DP
    for (int k = SIZE - 1; k >= 0; k--)
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                trans[i][j] = trans[i][j] || (trans[i][k] && trans[k][j]);
    while (m--)
    {
        flag = true;
        cin >> a >> b;
        if (a.size() != b.size())
        {
            cout << "no" << endl;
            continue;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (!trans[a[i] - 'a'][b[i] - 'a'])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}