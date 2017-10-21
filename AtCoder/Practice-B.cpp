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
        m[make_pair(b, a)] = ch == '>' ? '<' : '>';
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

int getPartion(vector<char> &v, int l, int r)
{
    char k = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (ask(v[j], k) == '<')
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quickAsk(vector<char> &v, int l, int r)
{
    int m;
    if (l < r)
    {
        m = getPartion(v, l, r);
        quickAsk(v, l, m - 1);
        quickAsk(v, m + 1, r);
    }
}

void bsort(vector<char> &v)
{
    int mid, l, r;
    char t;
    for (int i = 1; i < v.size(); i++)
    {
        l = 0;
        r = i - 1;
        t = v[i];
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (ask(v[mid], t) == '>')
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (int j = i; j > l; j--)
            v[j] = v[j - 1];
        v[l] = t;
    }
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
            bsort(v);
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