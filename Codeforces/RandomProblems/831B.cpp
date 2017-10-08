#include <iostream>
#include <string>

using namespace std;

char table[26] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    char ch;
    cin >> t;
    for (int i = 0; i < 26; i++)
    {
        cin >> ch;
        table[t[i] - 'a'] = ch;
    }
    cin >> t;
    for (int i = 0; i < t.size(); i++)
    {
        if ('A' <= t[i] && t[i] <= 'Z')
            cout << (char)(table[t[i] - 'A'] - 32);
        else if ('a' <= t[i] && t[i] <= 'z')
            cout << table[t[i] - 'a'];
        else
            cout << t[i];
    }
    cout << endl;
    return 0;
}