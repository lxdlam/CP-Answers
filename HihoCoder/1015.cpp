#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MEM(x) memset(x, 0, sizeof(x))

const int SIZE = 1e4 + 10;

int KMPnext[SIZE] = {0};

void getNext(const string &s)
{
    MEM(KMPnext);
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (k > 0 && s[k] != s[i])
        {
            k = KMPnext[k];
        }
        KMPnext[i + 1] = ++k;
    }
}

int match(const string &t, const string &p)
{
    int count = 0;
    getNext(p);
    int q = 0;
    for (int i = 0; i < t.size(); i++)
    {
        while (q > 0 && p[q] != t[i])
            q = KMPnext[q];
        q++;
        if (q == p.size())
        {
            count++;
            q = KMPnext[q];
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string p, t;
    cin >> n;
    while (n--)
    {
        cin >> p >> t;
        cout << match(t, p) << endl;
    }
    return 0;
}