#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 1500 + 10;

ll c[SIZE][SIZE] = {0};

void getCom()
{
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) & 1;
        // Will be extremely large!
    }
}

inline int lowbit(int k)
{
    return k & (-k);
}

void update(vi &v, int pos, int val)
{
    int len = v.size();
    while (pos < len)
    {
        //change behavior here
        v[pos] += val;
        pos += lowbit(pos);
    }
}

int getVal(vi &v, int pos)
{
    int res = 0;
    while (pos)
    {
        res += v[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    getCom();
    ll ans = 0;
    cin >> n;
    vi v(n + 1), vk(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vk[i];
        update(v, vk[i], 1);
        ans += i - getVal(v, vk[i]);
    }
    ans &= 1;
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        ans += c[y - x + 1][2] & 1;
        if (ans & 1)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
        ans &= 1;
    }
    return 0;
}