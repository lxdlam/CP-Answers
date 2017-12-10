#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, res;
    string t;
    cin >> T;
    while (T--)
    {
        cin >> t;
        res = 0;
        for (auto i : t)
            res += i - 'A' + 1;
        cout << res << endl;
    }

    return 0;
}