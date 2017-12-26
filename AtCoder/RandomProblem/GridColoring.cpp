#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 100 + 10;

int board[SIZE][SIZE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    int n;
    cin >> h >> w >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int i = 0, j = 0, k = 0;
    while (i != h && j != w)
    {
        if (v[k] == 0)
            k++;
        board[i][j] = k + 1;
        v[k]--;
        if (i & 1)
            j--;
        else
            j++;
        if (j == -1)
            i++, j = 0;
        else if (j == w)
            i++, j = w - 1;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    return 0;
}