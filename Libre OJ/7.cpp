#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int N = 3e6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long t, num = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        num ^= t;
    }
    cout << num << endl;

    return 0;
}