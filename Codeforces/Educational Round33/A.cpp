#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int player[] = {0, 1, 2, 3};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool flag = true;
    int p1 = 1, p2 = 2, spe = 3;
    int p;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> p;
        if (p == spe)
            flag = false;
        else
        {
            if (p1 == p)
                swap(p2, spe);
            else if (p2 == p)
                swap(p1, spe);
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}