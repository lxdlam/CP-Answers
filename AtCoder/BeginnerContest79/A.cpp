#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string pattern[] = {"000", "111", "222", "333", "444", "555", "666", "777", "888", "999"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    bool found = false;
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        if (n.find(pattern[i]) != string::npos)
            found = true;
    }
    if (found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}