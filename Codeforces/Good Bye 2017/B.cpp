#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 50 + 10;

char board[SIZE][SIZE] = {0};

int n, m;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

vi v{0, 1, 2, 3};

bool isOk(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    else
        return board[x][y] != '#';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sx, sy;
    int ex, ey;
    int tx, ty;
    string s;
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
                sx = i, sy = j;
            if (board[i][j] == 'E')
                ex = i, ey = j;
        }
    }
    cin >> s;
    int cnt = 0;
    do
    {
        tx = sx, ty = sy;
        for (auto i : s)
        {
            tx += dir[v[i - '0']][0];
            ty += dir[v[i - '0']][1];
            if (!isOk(tx, ty))
                break;
            if (tx == ex && ty == ey)
            {
                cnt++;
                break;
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;

    return 0;
}