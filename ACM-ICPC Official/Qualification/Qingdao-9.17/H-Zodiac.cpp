#include <iostream>
#include <string>

using namespace std;

string token[12] = {
    "rat", "ox", "tiger", "rabbit", "dargon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int posA, posB, res;
    string a, b;
    cin >> T;
    while (T--)
    {
        posA = posB = res = 0;
        cin >> a >> b;
        for (int i = 0; i < 12; i++)
        {
            if (a == token[i])
                posA = i;
            if (b == token[i])
                posB = i;
        }
        res = posB - posA;
        if (res <= 0)
            res += 12;
        cout << res << endl;
    }
    return 0;
}