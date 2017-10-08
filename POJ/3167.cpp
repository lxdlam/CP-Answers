// not solved!
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi t, p, tls, pls, teq, peq, ans, tgt, pgt;

void pre(vi &lt, vi &eq, vi &gt, vi &v)
{
    for (int i = 0; i < p.size(); i++)
    {
        lt.push_back(0);
        eq.push_back(0);
        gt.push_back(0);
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
                lt[i]++;
            else if (v[j] == v[i])
                eq[i]++;
            else if (v[j] > v[i])
                gt[i]++;
        }
    }
}

//kmp
void getNext(vi &next)
{
    int j;
    next.push_back(-1);
    j = next[0];
    for (int i = 0; i < p.size(); i++)
    {
        while (j != -1 && (pls[i] != pls[j] || peq[i] != peq[j] || pgt[j] != pgt[i]))
            j = next[j];
        next.push_back(++j);
    }
}

void match()
{
    vi next;
    int count = 0;
    int j = 0;
    getNext(next);
    for (int i = 0; i < t.size(); i++)
    {
        while (j != -1 && (tls[i] != pls[j] || teq[i] != peq[j] || tgt[i] != pgt[j]))
            j = next[j];
        j++;
        if (j == p.size())
        {
            ans.push_back(i - j + 2);
            j = next[j];
        }
    }
}

void solve()
{
    pre(tls, teq, tgt, t);
    pre(pls, peq, pgt, p);
    match();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, s, tmp;
    while (n--)
    {
        cin >> tmp;
        t.push_back(tmp);
    }
    while (k--)
    {
        cin >> tmp;
        p.push_back(tmp);
    }
    solve();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}