// Source: https://open.kattis.com/problems/patuljci
// From: Croatian Open Competition in Informatics 2006/2007, contest #3

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int SIZE = 9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    int t, ta, tb, tc;
    bool found = false;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> t;
        v.emplace_back(t);
    }
    for (int i = 0; i < SIZE; i++)
    {
        ta = v[i];
        v[i] = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            tb = v[j];
            v[j] = 0;
            if (accumulate(v.begin(), v.end(), 0) == 100)
            {
                found = true;
                break;
            }
            v[j] = tb;
        }
        if (found)
            break;
        v[i] = ta;
    }
    for (auto i : v)
    {
        if (i != 0)
            cout << i << endl;
    }
    return 0;
}