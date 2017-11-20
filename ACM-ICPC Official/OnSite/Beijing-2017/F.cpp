#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 100 + 10;
char board[SIZE][SIZE] = {0};
string t;

void read(int n)
{
    int p = 0, q = 0;
    bool down = false;
    while (q < n && p < n)
    {
        t += board[p][q];
        if (!p && !down)
        {
            q++;
            down = !down;
        }
        else if (!q && down)
        {
            p++;
            down = !down;
        }
        else if (down)
            p++, q--;
        else
            p--, q++;
    }

    while (p >= 0 && q >= 0)
    {
        t += board[p][q];
        if (p == n && down)
        {
            q++;
            down = !down;
        }
        else if (q == n && !down)
        {
            p++;
            down = !down;
        }
        else if (down)
            p++, q--;
        else
            p--, q++;
    }
}

void solve(int N)
{
    // solve it!!!
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    while (cin >> n)
    {
        cin.get();
        t.clear();
        memset(board, 0, sizeof(board));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                board[i][j] = cin.get();
            cin.get();
        }

        read(n);
        solve(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j];
            cout << endl;
        }
    }

    return 0;
}