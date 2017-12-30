#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, tmp, cnt = INT_MAX, cur;
    cin >> n >> a >> b;
    vector<int> v;
    for (int i = 0; i < 4; i++)
        v.emplace_back(a);
    for (int i = 0; i < 2; i++)
        v.emplace_back(b);

    sort(v.begin(), v.end());

    // permutation + greedy
    do
    {
        tmp = 1, cur = n;
        for (int i = 0; i < 6; i++)
        {
            if (cur < v[i])
                cur = n, tmp++;
            cur -= v[i];
        }
        cnt = min(cnt, tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;

    return 0;
}