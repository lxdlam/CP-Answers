// Source: https://open.kattis.com/problems/esej
// From: Croatian Open Competition in Informatics 2015/2016, contest #3

#include <iostream>

using namespace std;

const string w = "abcdefghijklmnopqrstuvwxyz";

const int l1 = 26;
const int l2 = 26 * 26;
const int l3 = 26 * 26 * 26;

void out(int i)
{
    if (i > l3)
        cout << w[i / l3] << w[(i - l3) / l2] << w[(i - l3 - l2) / l1] << w[i % l1] << " ";
    else if (i > l2)
        cout << w[i / l2] << w[(i - l2) / l1] << w[i % l1] << " ";
    else if (i > l1)
        cout << w[i / l1] << w[i % l1] << " ";
    else
        cout << w[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    n = max(n, (m / 2) + 1);
    for (int i = 0; i < n; i++)
        out(i);
    cout << endl;
    return 0;
}