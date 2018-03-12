#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int count = 0, i = 1;
    for (int j = 0; j < 12; j++)
    {
        if (a[j] != '-')
        {
            count += i * (a[j] - '0');
            i++;
        }
    }
    if (count % 11 == 10)
    {
        if (a[12] == 'X')
            cout << "Right" << endl;
        else
        {
            a[12] = 'X';
            cout << a << endl;
        }
    }
    else
    {
        if (a[12] == count % 11 + '0')
            cout << "Right" << endl;
        else
        {
            a[12] = count % 11 + '0';
            cout << a << endl;
        }
    }
    return 0;
}