#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 6;
char board[SIZE][SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kase = 0;
    int x, y;
    char op;
    bool flag;
    while (true)
    {
        kase++;
        flag = true;
        memset(board, 0, sizeof(board));
        x = y = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board[i][j] = cin.get();
                if (board[i][j] == ' ')
                    x = i, y = j;
                else if (board[i][j] == 'Z')
                    return 0;
            }
            cin.get();
        }
        while (cin >> op && op != '0')
        {
            if (op == 'A' && x - 1 >= 0)
            {
                swap(board[x - 1][y], board[x][y]);
                x--;
            }
            else if (op == 'B' && x + 1 < 5)
            {
                swap(board[x + 1][y], board[x][y]);
                x++;
            }
            else if (op == 'L' && y - 1 >= 0)
            {
                swap(board[x][y - 1], board[x][y]);
                y--;
            }
            else if (op == 'R' && y + 1 < 5)
            {
                swap(board[x][y + 1], board[x][y]);
                y++;
            }
            else
                flag = false;
        }
        cout << (kase == 1 ? "" : "\n") << "Puzzle #" << kase << ":" << endl;
        if (!flag)
            cout << "This puzzle has no final configuration." << endl;
        else
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                    cout << board[i][j] << (j == 4 ? "" : " ");
                cout << endl;
            }
        }
        cin.get();
    }
}