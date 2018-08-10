#include <iostream>

using namespace std;

const int MAXN = 110;

int num[MAXN] = {0};

void init()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (!num[i])
            num[++num[0]] = i;
        for (int j = 1; j <= num[0] && num[j] <= MAXN / i; j++)
        {
            num[num[j] * i] = 1;
            if (i % num[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= MAXN; i++)
        num[i] = num[i] * num[i] - i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T, t;
    cin >> T;
    while (T--)
    {
        cin >> t;
        cout << num[t] << endl;
    }
    return 0;
}