#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

inline string to_string(int a)
{
    string res = "";
    while (a)
    {
        res.push_back(a % 10 + '0');
        a /= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<string> hash;

    int T, n, t;
    int k;
    bool valid;
    string a, b, c;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        cin >> n;
        hash.clear();
        valid = true;
        for (int i = 0; i < n * n; i++)
        {
            for (int j = 0; j < n * n; j++)
            {
                cin >> t;
                if (t < 1 || t > n * n)
                    valid = false;
                a = to_string(t) + " shows on row " + to_string(i);
                b = to_string(t) + " shows on column " + to_string(j);
                c = to_string(t) + " shows on section " + to_string(i / n) + "," + to_string(j / n);
                if (hash.count(a) || hash.count(b) || hash.count(c))
                    valid = false;
                hash.insert(a);
                hash.insert(b);
                hash.insert(c);
            }
        }
        if (valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}