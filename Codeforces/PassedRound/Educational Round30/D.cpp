#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi res;
int n, k;

void genList(int size)
{
    for (int i = 1; i <= size; i++)
        res.emplace_back(i);
}

void bre(int l, int r)
{
    if (k < 1 || l + 1 == r)
        return;
    k -= 2;
    int mid = (l + r) >> 1;
    swap(res[mid - 1], res[mid]);
    bre(l, mid);
    bre(mid, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if (k % 2 == 0 || n * 2 < k)
        cout << -1 << endl;
    else
    {
        genList(n);
        k--;
        bre(0, n);
        for (auto i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}