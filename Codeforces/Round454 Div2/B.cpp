#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 81 + 10;

char board[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    bool flag = false;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i * 9 + j] = cin.get();
            if (j % 3 == 2)
                cin.get();
        }
        if (i % 3 == 2 && i != 8)
            cin.get();
    }
    cin >> m >> n;
    m--, n--;
    m %= 3, n %= 3;
    for (int i = m * 3; i < m * 3 + 3; i++)
        for (int j = n * 3; j < n * 3 + 3; j++)
            if (board[i * 9 + j] == '.')
                flag = true;

    if (flag)
    {
        for (int i = m * 3; i < m * 3 + 3; i++)
            for (int j = n * 3; j < n * 3 + 3; j++)
                if (board[i * 9 + j] == '.')
                    board[i * 9 + j] = '!';
    }
    else
    {
        for (int i = 0; i < 81; i++)
            if (board[i] == '.')
                board[i] = '!';
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i * 9 + j];
            if (j % 3 == 2)
                cout << ' ';
        }
        cout << endl;
        if (i % 3 == 2)
            cout << endl;
    }

    return 0;
}