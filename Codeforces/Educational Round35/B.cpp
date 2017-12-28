#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if (a > b)
        swap(a, b);

    int avr = (a + b) / n;
    int minn = avr;

    if (a % avr == 0)
        cout << avr << endl;
    else
        cout << a % avr << endl;

    return 0;
}