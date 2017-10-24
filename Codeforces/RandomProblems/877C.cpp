#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    cout << k + k / 2 << endl;
    for (int i = 2; i <= k; i += 2)
        cout << i << " ";
    for (int i = 1; i <= k; i += 2)
        cout << i << " ";
    for (int i = 2; i <= k; i += 2)
        cout << i << " ";
    cout << endl;
    return 0;
}