#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

vi pp(1e5 + 10);

inline int lowbit(int k)
{
    return k & -k;
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

const int SIZE = 1e5 + 10;

bool notprime[SIZE] = {false};

void init()
{
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < SIZE; i++)
        if (!notprime[i])
        {
            if (i > SIZE / i)
                continue;
            for (int j = i * i; j < SIZE; j += i)
                notprime[j] = true;
        }
    for (int i = 1; i < SIZE; i++)
        update(pp, i, !notprime[i] && !notprime[(i + 1) / 2] ? 1 : 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << getVal(pp, r) - getVal(pp, l - 1) << endl;
    }

    return 0;
}