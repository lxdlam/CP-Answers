#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string fly;
    int T, sf = 0, fs = 0;
    cin >> T >> fly;
    for (int i = 0; i < T - 1; i++)
    {
        if (fly[i] == 'S' && fly[i + 1] == 'F')
            sf++;
        else if (fly[i] == 'F' && fly[i + 1] == 'S')
            fs++;
    }
    if (sf > fs)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}