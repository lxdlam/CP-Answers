#include <iostream>
#include <cstdio>

using namespace std;

const int SIZE = 1e6 + 10;

long long cubic[SIZE] = {0};

void init()
{
    for (int i = 1; i < SIZE; i++)
        cubic[i] = 3 * i * (i + 1) + 1;
}

int main()
{
    init();
    int T;
    cin >> T;
    long long t;
    bool flag;
    while (T--)
    {
        flag = false;
        scanf("%lld", &t);
        for (int i = 0; i < SIZE; i++)
        {
            if (cubic[i] == t)
            {
                flag = true;
                cout << "YES\n";
                break;
            }
            else if (cubic[i] > t)
            {
                flag = true;
                cout << "NO\n";
                break;
            }
        }
        if (!flag)
            cout << "NO\n";
    }
    return 0;
}