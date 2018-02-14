#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fp1 = "What are you doing while sending \"";
string fp2 = "\"? Are you busy? Will you send \"";
string fp3 = "\"?";

const int SIZE = 1e5 + 10;

unsigned long long l[SIZE] = {75};

void init()
{
    for (int i = 1; i < SIZE; i++)
        l[i] = i <= 54 ? 2 * l[i - 1] + 68 : l[i - 1];
}

ll k;

bool dfs(int n)
{
    if (k >= l[n])
    {
        k -= l[n];
        return false;
    }
    if (k < 0)
        return false;
    if (n == 0 && k < 75LL)
    {
        cout << f0[k];
        return true;
    }
    else if (n == 0)
    {
        k -= 75;
        return false;
    }

    if (k < 34LL)
    {
        cout << fp1[k];
        return true;
    }

    k -= 34;

    if (dfs(n - 1))
        return true;

    if (k < 32LL)
    {
        cout << fp2[k];
        return true;
    }

    k -= 32;

    if (dfs(n - 1))
        return true;

    if (k < 2LL)
    {
        cout << fp3[k];
        return true;
    }
    k -= 2;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    //Max length of n is 54.

    init();
    int T;
    int n;
    cin >> T;
    bool flag;
    while (T--)
    {
        cin >> n >> k;
        k--;
        flag = dfs(n);
        if (!flag)
            cout << '.';
    }
    cout << endl;

    return 0;
}