#include <iostream>

using namespace std;

const int SIZE = 4;

int board[SIZE][SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int op;
    bool change = false;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    cin >> op;
    if (op == 0)
    {
        //left
        for (int i = 0; i < SIZE; i++)
        {
            change = false;
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[i][j] != 0)
                    continue;
                for (int k = j + 1; k < SIZE; k++)
                {
                    if (board[i][k] != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        break;
                    }
                }
            }

            if (board[i][0] == board[i][1])
            {
                board[i][0] *= 2;
                board[i][1] = 0;
                change = true;
            }
            if (board[i][2] == board[i][3])
            {
                board[i][2] *= 2;
                board[i][3] = 0;
                change = true;
            }
            else if (board[i][1] == board[i][2] && !change)
            {
                board[i][1] *= 2;
                board[i][2] = 0;
            }

            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[i][j] != 0)
                    continue;
                for (int k = j + 1; k < SIZE; k++)
                {
                    if (board[i][k] != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        break;
                    }
                }
            }
        }
    }
    else if (op == 1)
    {
        //up
        for (int i = 0; i < SIZE; i++)
        {
            change = false;
            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[j][i] != 0)
                    continue;
                for (int k = j + 1; k < SIZE; k++)
                {
                    if (board[k][i] != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        break;
                    }
                }
            }

            if (board[0][i] == board[1][i])
            {
                board[0][i] *= 2;
                board[1][i] = 0;
                change = true;
            }
            if (board[2][i] == board[3][i])
            {
                board[2][i] *= 2;
                board[3][i] = 0;
                change = true;
            }
            else if (board[1][i] == board[2][i] && !change)
            {
                board[1][i] *= 2;
                board[2][i] = 0;
            }

            for (int j = 0; j < SIZE - 1; j++)
            {
                if (board[j][i] != 0)
                    continue;
                for (int k = j + 1; k < SIZE; k++)
                {
                    if (board[k][i] != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        break;
                    }
                }
            }
        }
    }
    else if (op == 2)
    {
        //right
        for (int i = 0; i < SIZE; i++)
        {
            change = false;
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[i][j] != 0)
                    continue;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (board[i][k] != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        break;
                    }
                }
            }

            if (board[i][2] == board[i][3])
            {
                board[i][3] *= 2;
                board[i][2] = 0;
                change = true;
            }
            if (board[i][0] == board[i][1])
            {
                board[i][1] *= 2;
                board[i][0] = 0;
                change = true;
            }
            else if (board[i][1] == board[i][2] && !change)
            {
                board[i][2] *= 2;
                board[i][1] = 0;
            }

            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[i][j] != 0)
                    continue;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (board[i][k] != 0)
                    {
                        swap(board[i][j], board[i][k]);
                        break;
                    }
                }
            }
        }
    }
    else if (op == 3)
    {
        //down
        for (int i = 0; i < SIZE; i++)
        {
            change = false;
            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[j][i] != 0)
                    continue;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (board[k][i] != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        break;
                    }
                }
            }

            if (board[2][i] == board[3][i])
            {
                board[3][i] *= 2;
                board[2][i] = 0;
                change = true;
            }
            if (board[0][i] == board[1][i])
            {
                board[1][i] *= 2;
                board[0][i] = 0;
                change = true;
            }
            else if (board[1][i] == board[2][i] && !change)
            {
                board[2][i] *= 2;
                board[1][i] = 0;
            }

            for (int j = SIZE - 1; j > 0; j--)
            {
                if (board[j][i] != 0)
                    continue;
                for (int k = j - 1; k >= 0; k--)
                {
                    if (board[k][i] != 0)
                    {
                        swap(board[j][i], board[k][i]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}