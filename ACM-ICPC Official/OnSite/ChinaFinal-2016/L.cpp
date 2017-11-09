#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 10 + 2;

int score[] = {3, 1, 0};
int table[SIZE][SIZE][SIZE][SIZE] = {0};

void init()
{
    int a, b, c, d;
    a = b = c = d = 0;
    // A B
    for (int i = 0; i < 3; i++)
    {
        a += score[i];
        b += score[2 - i];
        // A C
        for (int j = 0; j < 3; j++)
        {
            a += score[j];
            c += score[2 - j];
            //A D
            for (int k = 0; k < 3; k++)
            {
                a += score[k];
                d += score[2 - k];
                // B C
                for (int l = 0; l < 3; l++)
                {
                    b += score[l];
                    c += score[2 - l];
                    // B D
                    for (int x = 0; x < 3; x++)
                    {
                        b += score[x];
                        d += score[2 - x];
                        // C D
                        for (int y = 0; y < 3; y++)
                        {
                            c += score[y];
                            d += score[2 - y];
                            table[a][b][c][d]++;
                            c -= score[y];
                            d -= score[2 - y];
                        }
                        b -= score[x];
                        d -= score[2 - x];
                    }
                    b -= score[l];
                    c -= score[2 - l];
                }
                a -= score[k];
                d -= score[2 - k];
            }
            a -= score[j];
            c -= score[2 - j];
        }
        a -= score[i];
        b -= score[2 - i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, a, b, c, d;
    init();
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> a >> b >> c >> d;
        cout << "Case #" << i << ": ";
        if (a >= 10 || b >= 10 || c >= 10 || d >= 10)
            cout << "Wrong Scoreboard" << endl;
        else
        {
            switch (table[a][b][c][d])
            {
            case 0:
                cout << "Wrong Scoreboard" << endl;
                break;
            case 1:
                cout << "Yes" << endl;
                break;
            default:
                cout << "No" << endl;
                break;
            }
        }
    }
    return 0;
}