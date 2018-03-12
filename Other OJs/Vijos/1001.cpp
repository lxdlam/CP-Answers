#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string name, fn;
    int fg, cg, paper;
    char carde, west;
    int max = 0, total = 0;
    int temp;
    cin >> n;
    while (n--)
    {
        temp = 0;
        cin >> name >> fg >> cg >> carde >> west >> paper;
        if (fg > 80 && paper >= 1)
            temp += 8000;
        if (fg > 85 && cg > 80)
            temp += 4000;
        if (fg > 90)
            temp += 2000;
        if (fg > 85 && west == 'Y')
            temp += 1000;
        if (cg > 80 && carde == 'Y')
            temp += 850;
        if (temp > max)
        {
            fn = name;
            max = temp;
        }
        total += temp;
    }
    cout << fn << endl
         << max << endl
         << total << endl;
    return 0;
}