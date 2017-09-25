#include <iostream>

using namespace std;

const int SIZE = 1e6 + 10;

long long table[SIZE] = {0};

void init()
{
    for (long long i = 0; i < SIZE; i++)
        table[i] = 3 * i * (i + 1) + 1;
}

int main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long cmp;
    int T;
    bool find;
    cin >> T;
    while (T--)
    {
        find = false;
        cin >> cmp;
        for (long long i = 0; i < SIZE; i++)
        {
            if (table[i] > cmp)
                break;
            if (table[i] == cmp)
            {
                find = true;
                break;
            }
        }
        if (find)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}