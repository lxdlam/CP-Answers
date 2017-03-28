/*
ID: lxdlam1
PROG: ride
LANG: C++11
*/

#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string a, b;
    fin >> a >> b;
    long la = 1, lb = 1;
    string::iterator it1 = a.begin(), it2 = b.begin();
    for (it1; it1 != a.end(); it1++)
        la *= *it1 - 'A' + 1;
    for (it2; it2 != b.end(); it2++)
        lb *= *it2 - 'A' + 1;
    fout << ((la % 47 == lb % 47) ? "GO" : "STAY") << endl;
    fin.close();
    cout.close();
    return 0;
}