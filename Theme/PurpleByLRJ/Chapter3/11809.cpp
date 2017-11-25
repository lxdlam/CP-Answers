#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 30 + 10;

const double EPS = 1e-5;

double m[SIZE][SIZE] = {0.0};
long long e[SIZE][SIZE] = {0};

void init()
{
    double t;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            t = log10(1 - pow(2, -1 - i)) + (pow(2, j) - 1) * log10(2);
            e[i][j] = t;
            m[i][j] = pow(10, t - e[i][j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    string num;
    double a;
    int b;
    while (cin >> num && num != "0e0")
    {
        for (auto &i : num)
            if (i == 'e')
                i = ' ';
        stringstream ss(num);
        ss >> a >> b;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                if (b == e[i][j] && abs(a - m[i][j]) < EPS)
                {
                    cout << i << ' ' << j << endl;
                    break;
                }
            }
        }
    }

    return 0;
}