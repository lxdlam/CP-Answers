#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string t;
    cin >> t;
    bool isOne = false;
    int cont = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '1' && !isOne)
            isOne = true;
        if (isOne && t[i] == '0')
            cont++;
    }

    if (isOne && cont >= 6)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}