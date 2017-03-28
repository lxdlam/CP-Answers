/*
ID: lxdlam1
PROG: friday
LANG: C++11
*/

#include <fstream>
#include <iostream>

using namespace std;

auto isLeap = [](int x) -> bool { return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0); };

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int month[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int days[7] = {0};
    int n;
    fin >> n;
    for (int i = 1900; i < 1900 + n; i++)
    {
        if (!isLeap(i) && !isLeap(i - 1))
            for (int j = 0; j < 12; j++)
                month[j] = (month[j] + 1) % 7;
        else if (isLeap(i))
        {
            month[0] = (month[0] + 1) % 7;
            month[1] = (month[1] + 1) % 7;
            for (int j = 2; j < 12; j++)
                month[j] = (month[j] + 2) % 7;
        }
        else if (isLeap(i - 1))
        {
            month[0] = (month[0] + 2) % 7;
            month[1] = (month[1] + 2) % 7;
            for (int j = 2; j < 12; j++)
                month[j] = (month[j] + 1) % 7;
        }
        for (int j = 0; j < 12; j++)
            days[month[j]]++;
    }
    fout << days[0];
    for (int j = 1; j < 7; j++)
        fout << " " << days[j];
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}