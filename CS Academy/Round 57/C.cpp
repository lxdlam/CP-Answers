#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;

inline int add(int i) { return i + 1 > n ? i + 1 - n : i + 1; }

inline int miu(int i) { return i - 1 < n ? i - 1 + n : i - 1; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, t;
    cin >> n >> k;
    set<int> fox, hp;
    vector<int> os, ts, ns;

    int count = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> t;
        fox.insert(t);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> t;
        hp.insert(t);
    }

    for (auto i : fox)
    {
        if (!hp.count(add(i)) && !hp.count(miu(i)))
            ns.emplace_back(i);
        else if (hp.count(add(i)) && hp.count(miu(i)))
            ts.emplace_back(i);
        else if (hp.count(add(i)) || hp.count(miu(i)))
            os.emplace_back(i);
    }

    for (auto i : os)
    {
        if (hp.count(add(i)))
            hp.erase(add(i));
        else
            hp.erase(miu(i));
    }

    for (auto i : ts)
        if (hp.count(add(i)) || hp.count(miu(i)))
            count++;

    cout << ns.size() * 2 + os.size() + count + (ts.size() - count) * 2 << endl;

    return 0;
}