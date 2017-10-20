// Fuck this problem
// Thanks to https://stackoverflow.com/questions/1534748/design-an-efficient-algorithm-to-sort-5-distinct-keys-in-fewer-than-8-comparison
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

map<pair<char, char>, char> m;

char ask(char a, char b)
{
    char ch;
    if (m[make_pair(a, b)] == 0)
    {
        cout << "? " << a << " " << b << endl;
        cin >> ch;
        m[make_pair(a, b)] = ch;
        return ch;
    }
    return m[make_pair(a, b)];
}

vector<char>
genVec(int size)
{
    vector<char> v;
    for (int i = 0; i < size; i++)
        v.emplace_back(i + 'A');
    return v;
}

int sort(vector<char> &v, int cnt, char c)
{
    int l = 0, r = cnt;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ask(c, v[mid]) == '>')
            l = mid + 1;
        else
            r = mid;
    }
    cnt++;
    if (ask(c, v[r]) == '>')
        r++;
    for (int i = cnt; i >= r + 1; i--)
        v[i] = v[i - 1];
    v[r] = c;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    char e;
    vector<char> v;
    if (n == 26)
    {
        v = genVec(n);
        if (q == 1000)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n - 1; j++)
                    if (ask(v[j], v[j + 1]) == '>')
                        swap(v[j], v[j + 1]);
        }
        else if (q == 100)
        {
            int cnt = 0;
            for (auto i : v)
                cnt = sort(v, cnt, i);
        }
    }
    else if (n == 5)
    {
        char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
        if (ask(a, b) == '>')
            swap(a, b);
        if (ask(c, d) == '>')
            swap(c, d);
        if (ask(a, c) == '>')
        {
            swap(a, c);
            swap(b, d);
        }

        if (ask(e, c) == '>')
        {
            if (ask(e, d) == '>')
            {
                if (ask(b, d) == '>')
                {
                    if (ask(b, e) == '>')
                        v = {a, c, d, e, b};
                    else
                        v = {a, c, d, b, e};
                }
                else
                {
                    if (ask(b, c) == '<')
                        v = {a, b, c, d, e};
                    else
                        v = {a, c, b, d, e};
                }
            }
            else
            {
                if (ask(b, e) == '>')
                {
                    if (ask(b, d) == '>')
                        v = {a, c, e, d, b};
                    else
                        v = {a, c, e, b, d};
                }
                else
                {
                    if (ask(b, c) == '<')
                        v = {a, b, c, e, d};
                    else
                        v = {a, c, b, e, d};
                }
            }
        }
        else
        {
            if (ask(e, a) == '<')
            {
                if (ask(b, c) == '>')
                {
                    if (ask(b, d) == '>')
                        v = {e, a, c, d, b};
                    else
                        v = {e, a, c, b, d};
                }
                else
                    v = {e, a, b, c, d};
            }
            else
            {
                if (ask(b, c) == '>')
                {
                    if (ask(b, d) == '>')
                        v = {a, e, c, d, b};
                    else
                        v = {a, e, c, b, d};
                }
                else
                {
                    if (ask(b, e) == '<')
                        v = {a, b, e, c, d};
                    else
                        v = {a, e, b, c, d};
                }
            }
        }
    }

    cout << "! ";
    for (auto i : v)
        cout << i;
    cout << endl;
    return 0;
}