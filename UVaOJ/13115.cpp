#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_set<string> hash;

    int T, n, t;
    int k;
    bool valid;
    string a, b, c;
    cin >> T;
    while (T--)
    {
        cin >> n;
        k = sqrt(n);
        hash.clear();
        valid = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> t;
                a = to_string(t) + " shows on row " + to_string(i);
                b = to_string(t) + " shows on column " + to_string(j);
                c = to_string(t) + " shows on section " + to_string(i / k) + "," + to_string(j / k);
                if (hash.count(a) || hash.count(b) || hash.count(c))
                    valid = false;
                hash.insert(a);
                hash.insert(b);
                hash.insert(c);
            }
        }
        if (valid)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}