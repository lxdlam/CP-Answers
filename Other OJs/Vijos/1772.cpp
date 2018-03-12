#include <iostream>

using namespace std;

bool isAll(int, int, int);

int main()
{
    for (int i = 111; i <= 333; i++)
        if (isAll(i, i * 2, i * 3))
            cout << i << " " << i * 2 << " " << i * 3 << endl;
}

bool isAll(int a, int b, int c)
{
    bool num[10];
    bool isRepeat = false;
    for (auto &i : num)
        i = false;
    while (a && b && c)
    {
        num[a % 10] = num[b % 10] = num[c % 10] = true;
        a /= 10;
        b /= 10;
        c /= 10;
    }
    for (int i = 1; i < 10; i++)
        if (!num[i])
        {
            isRepeat = true;
            break;
        }
    return !isRepeat && !num[0];
}